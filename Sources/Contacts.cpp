#include <iostream>  // Gestion des entrees et sorties

#include "../Headers/Contacts.h"  // Pour la declaration de la classe


//  Constructor
Contacts::Contacts(){
    // Inisialiser les structures de control a NULL
    head = NULL;
    current = NULL;
    temp = NULL;
};

// Ajouter un contact
void Contacts::ajouterContact(std::string c_name, std::string c_number, std::string c_email, std::string c_addr){
    contactPtr new_contact = new contactInfos;  // Creer un pointeur sur la nouvelle liste
    
    // Verifier si le nom est vide
    if (c_name == ""){
        new_contact->full_name = c_number;  // Si c'est le cas on va stocker son numero a la place du nom
    }

    new_contact->full_name = c_name;
    new_contact->phone_number = c_number;
    new_contact->email = c_email;
    new_contact->address = c_addr;

    // Verifier si c'est notre liste chainee n'est pas vide
    if (head != NULL){
        current = head;  // Mettre l'element actuel egal au debut
        temp = head;  // Mettre l'element precedent egal au debut

        std::string lower_case_name(this->lowerCaseName(c_name));  // Rendre le nom miniscule pour le comparer

        // Parcourez toutes les listes jusqu’à ce que nous trouvions le bon endroit pour le nouveau contact
        while (this->lowerCaseName(current->full_name) < lower_case_name && current->next != NULL){
            temp = current;  // Element precedent
            current = current->next;  // On va avancer l'element courrent
        }
        // Verifier si nous avons trouve le bon endroit
        if (this->lowerCaseName(current->full_name) > lower_case_name){
            /* 
            Verifier si l'element precedent egal a la tete
            Si oui on va associer la tete au nouveau contact
            Si non l'element suivant d'element temp va pointer sur le nouveau element
            Et l'element suivant du nouveau contact va pointer sur l'element courrant
            */
            if (head == temp){
                head = new_contact;
            }
            else {
                temp->next = new_contact;
            }
            new_contact->next = current;

        }
        // Sinon l'element suivant d'element courrant va pointer sur le nouveau contact
        // et l'element suivant du nouveau contact va pointer sur NULL
        else {
            current->next = new_contact;
            new_contact->next = NULL;
        }
    }
    // Si la liste chainee est vide alors ce nouveau contact el le seul
    else { 
        head = new_contact;
        new_contact->next = NULL;
    }
    std::cout << "-> Contact a ete bien ajouter!" << std::endl;
    std::cout << "\n" << std::endl;
};

// Modifier un contact
void Contacts::modiferContact(std::string number){
    // Creer trois pointeurs pour le controle
    contactPtr modifyContactPtr = NULL;  // Pour trouver la place d'element a modifier
    contactPtr previous = NULL;  // L'element precedent de modifyContactPtr
    contactPtr after = NULL;  // L'element suivant de modifyContactPtr
    
    // Inisialiser tous au debut
    current = head;
    temp = head;
    previous = head;

    // Chercher l'enplacement de l'element a modifier
    while (current != NULL && current->phone_number != number){
        previous = current;  // Stocker le contact precedent du contact a modifier
        current = current->next;
    }

    // Verifier s'il n'existe pas
    if (current == NULL){ 
        std::cout << "\nAucun contact n'est associe a ce numero de telephone " << number << std::endl;
    }
    // Le cas s'il existe
    else {
        modifyContactPtr = current;  // L'element courrant c'est notre contact a modfier
        after = modifyContactPtr->next;  // Stocker le contact suivant de contact a modifier

        char response;

        // Changer le nom
        std::cout << "\nLe nom actuel de ce contact est:   ' " << modifyContactPtr->full_name << " '" << std::endl;
        std::cout << "Voulez vous le changer (Y/N)? ";
        std::cin >> response;
        std::cin.ignore();

        /*
        S'il veut changer le nom on va chercher l'emplacement correct du contact
        se nouveau nom qu'il a choisit
        */
        if ('y' == tolower(response)){
            std::string new_name;  // Nouveau nom
            std::cout << "Entrer le nouveau nom de votre contact:  ";
            std::getline(std::cin, new_name);

            std::string lower_case_name(this->lowerCaseName(new_name));

            current = head;
            temp = head;

            // Chercher l'emplacement du contact avec son nouveau nom
            while (this->lowerCaseName(current->full_name) < lower_case_name && current->next != NULL){
                temp = current;
                current = current->next;
            }
            // Si son emplacement ne change pas on va rien faire
            if (current == modifyContactPtr){}
            // Sinon on va changer son enplacement
            else {
                if (this->lowerCaseName(current->full_name) > lower_case_name){
                    /* 
                    Verifier si l'element precedent de lemplacement correct  est egal a l'entete
                    On va associer l'entete au contact a modifer
                    Sinon l'element suivant d'element precedent va pointer sur le contact a modefier
                    Et le suivant de ce dernier va pointer sur l'element courrant
                    */
                    if (head == temp){
                        head = modifyContactPtr;
                    }
                    else {
                        temp->next = modifyContactPtr;
                    }
                    modifyContactPtr->next = current;

                    /*
                    Si le contact a modifier est le premier on va associer l'entete avec le contact suivant
                    Sinon on va lier l'element precedent avec l'element suivant
                    */
                    if (head == previous) {
                        head = after;
                    }
                    else {
                        previous->next = after;
                    }

                }
                
                // Si sont emplacement est a la fin
                else {
                    current->next = modifyContactPtr;
                    modifyContactPtr->next = NULL;
                    if (head == previous) {
                        head = after;
                    }
                    else {
                        previous->next = after;
                    }
                }
            }
            // Changer le nom
            modifyContactPtr->full_name = new_name;
        }

        // Changer le telephone
        std::cout << "Le numero de telephone actuel de ce contact est:   ' " << modifyContactPtr->phone_number << " '" << std::endl;
        std::cout << "Voulez vous le changer (Y/N)? ";
        std::cin >> response;
        std::cin.ignore();
        if ('y' == tolower(response)){
            std::string new_phone;
            std::cout << "Entrer le nouveau numero de telephone de votre contact:  ";
            std::getline(std::cin, new_phone);
            
            modifyContactPtr->phone_number = new_phone;
        }

        // Changer l'email
        std::cout << "L'email actuel de ce contact est:   ' " << modifyContactPtr->email << " '" << std::endl;
        std::cout << "Voulez vous la changer (Y/N)? ";
        std::cin >> response;
        std::cin.ignore();
        if ('y' == tolower(response)){
            std::string new_mail;
            std::cout << "Entrer la nouvelle addresse mail de votre contact:  ";
            std::getline(std::cin, new_mail);
            
            modifyContactPtr->email = new_mail;
        }

        // Changer l'addresse
        std::cout << "L'addresse actuel de ce contact est:   ' " << modifyContactPtr->address << " '" << std::endl;
        std::cout << "Voulez vous la changer (Y/N)? ";
        std::cin >> response;
        std::cin.ignore();
        if ('y' == tolower(response)){
            std::string new_adr;
            std::cout << "Entrer nouvelle de votre contact:  ";
            std::getline(std::cin, new_adr);
            
            modifyContactPtr->address = new_adr;
        }
        std::cout << "Modefication complete !\n" << std::endl;
    }
    std::cout << "\n" << std::endl;
};

// Supprimer un contact
void Contacts::supprimerContact(std::string number){
    // Creer le pointeur pour obtenir le contact a supprimer
    contactPtr contact_to_delete = NULL;

    current = head;
    temp = head;

    // Chercher le contact avec son numero
    while (current != NULL && current->phone_number != number){
        temp = current;
        current = current->next;
    }
    if (current == NULL){ 
        std::cout << "Aucun contact n'est associe a ce numero de telephone " << number << std::endl;
    }
    else {
        contact_to_delete = current;
        current = current->next;
        temp->next = current;
        if (contact_to_delete == head){
            head = head->next;
            temp = NULL;
        }
        delete contact_to_delete;

        std::cout << "Ce contact a ete bien supprimer!" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

// Afficher les contacts
void Contacts::afficherContacts(){
    current = head;
    int nb_contacts(0);

    while (current != NULL){
        nb_contacts++;
        std::cout << " ------------------------------------------------------" <<std::endl;
        std::cout << "| Nom\t\t: " << current->full_name << std::endl;
        std::cout << "| Numero\t: " << current->phone_number << std::endl;
        std::cout << "| Addresse mail\t: " << current->email << std::endl;
        std::cout << "| Addresse\t: " << current->address << std::endl;
        std::cout << " ------------------------------------------------------" <<std::endl;

        current = current->next;
    }

    switch (nb_contacts)
    {
    case 0:
        std::cout << "-> Vous n'avez pas de contacts!" << std::endl;
        break;
    case 1:
        std::cout << "-> Vous avez un seul contact!" << std::endl;
        break;
    default:
        std::cout << "-> Vous avez "<< nb_contacts <<  " contacts!" << std::endl;
        break;
    }
    std::cout << "\n" << std::endl;
}

// Chercher un contact
void Contacts::chercherContact(){
    int choice;

    std::cout << "\n\tVoulez vous chercher :" << std::endl;
    std::cout << "\t\t 1) Par son numero de telephone" << std::endl;
    std::cout << "\t\t 2) Par la premiere lettre" << std::endl;
    std::cout << "\t\t 3) Par les deux premieres lettres" << std::endl;
    std::cout << "\n\tEntrer le numero de votre choix: ";
    std::cin >> choice;
    std::cin.ignore();

    switch(choice){
        case 1:{
            int nb_contacts(0);
            std::string contact_phone;
            std::cout << "Entrer le numero de telephone\t: ";
            std::cin >> contact_phone;
            std::cin.ignore();

            current = head;
            while (current != NULL){
                if (current->phone_number == contact_phone){
                    nb_contacts++;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                    std::cout << "| Nom\t\t: " << current->full_name << std::endl;
                    std::cout << "| Numero\t: " << current->phone_number << std::endl;
                    std::cout << "| Addresse mail\t: " << current->email << std::endl;
                    std::cout << "| Addresse\t: " << current->address << std::endl;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                }
            current = current->next;
            }
            if (nb_contacts == 0){std::cout << "Aucun contact est associe avec ce numero de telephone (" << contact_phone << ")!" << std::endl;}
            else {std::cout << "Nombre total de contact trouve est: " << nb_contacts << std::endl;}
            break;
        }
        case 2:{
            int nb_contacts(0);
            char first_char;
            std::cout << "Entrer la premiere lettre de votre nom de contact: ";
            std::cin >> first_char;
            std::cin.ignore();

            current = head;
            while (current != NULL){
                if (current->full_name[0] == first_char){
                    nb_contacts++;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                    std::cout << "| Nom\t\t: " << current->full_name << std::endl;
                    std::cout << "| Numero\t: " << current->phone_number << std::endl;
                    std::cout << "| Addresse mail\t: " << current->email << std::endl;
                    std::cout << "| Addresse\t: " << current->address << std::endl;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                }
            current = current->next;
            }
            if (nb_contacts == 0){std::cout << "Aucun contact commence par '" << first_char << "'" << std::endl;}
            else {std::cout << "Nombre total de contact trouve est: " << nb_contacts << std::endl;}
            break;
        }
        case 3:{
            int nb_contacts(0);
            char first_char[2];
            std::cout << "Entrer les deux premiere lettres de votre nom de contact: ";
            std::cin >> first_char;
            std::cin.ignore();

            current = head;
            while (current != NULL){
                if (current->full_name[0] == first_char[0] && current->full_name[1] == first_char[1]){
                    nb_contacts++;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                    std::cout << "| Nom\t\t: " << current->full_name << std::endl;
                    std::cout << "| Numero\t: " << current->phone_number << std::endl;
                    std::cout << "| Addresse mail\t: " << current->email << std::endl;
                    std::cout << "| Addresse\t: " << current->address << std::endl;
                    std::cout << " ------------------------------------------------------" <<std::endl;
                }
            current = current->next;
            }
            if (nb_contacts == 0){std::cout << "Aucun contact commence par '" << first_char << "'" << std::endl;}
            else {std::cout << "Nombre total de contact trouve est: " << nb_contacts << std::endl;}
            break;
        }
        
        default:
            std::cout << "Le numero du choix choisie n'exisete pas !!!" << std::endl;
    }
    std::cout << "\n" << std::endl;
};

// Sauvgarder les contacts
void Contacts::saveContacts(){
    int nb_contacts(0);
    std::string const file_path("Mes_Contacts.txt");
    std::ofstream file_handle(file_path.c_str());

    if (file_handle){
        current = head;
        file_handle << "\t\t\t ----------------------------------- " << std::endl;
        file_handle << "\t\t\t|\tListes des contacts\t    |" << std::endl;
        file_handle << "\t\t\t ----------------------------------- " << std::endl;
        while(current != NULL){
            nb_contacts++;

            file_handle << " ------------------------------------------------------" <<std::endl;
            file_handle << "| Nom\t\t: " << current->full_name << std::endl;
            file_handle << "| Numero\t: " << current->phone_number << std::endl;
            file_handle << "| Addresse mail\t: " << current->email << std::endl;
            file_handle << "| Addresse\t: " << current->address << std::endl;
            file_handle << " ------------------------------------------------------" <<std::endl;

            current = current->next;
        }
        switch(nb_contacts){
            case 0:
                std::cout << "Aucun contact trouve pour le sauvgarder!" << std::endl;
                break;
            default:
                std::cout << nb_contacts << " contacts ont ete bien sauvgarder dans le fichier => " << file_path << std::endl;
        }
            
        file_handle.close();
    }
    else{
        std::cout << "Une erreur lors de l'ouverture du fichier pour sauvgarder les contacts !!" << std::endl;
    }
}

std::string Contacts::lowerCaseName(std::string name){
    std::string lower_case(name);
    std::transform(lower_case.begin(), lower_case.end(), lower_case.begin(), ::tolower);
    
    return lower_case;
};