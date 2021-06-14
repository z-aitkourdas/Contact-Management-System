#include <iostream>
#include "../Headers/Contacts.h"

void afficherMenu();

int main(int argc, char** argv){
    Contacts mes_contacts;

    int option;
    system("pause");
    do {
        system("CLS");
        afficherMenu();
        std::cout << "\n\t Entrer le numero de votre choix: ";
        std::cin >> option;
        std::cin.ignore();

        switch(option){
            case 1:
                // Afficher la listes des contacts
                system("CLS");

                std::cout << "\t\t\t ----------------------------------- " << std::endl;
                std::cout << "\t\t\t|\tAffichage des contacts\t    |" << std::endl;
                std::cout << "\t\t\t ----------------------------------- " << std::endl;

                mes_contacts.afficherContacts();

                system("pause");
                break;
            case 2: {
                // Ajouter un contact
                system("CLS");

                std::cout << "\t\t\t ---------------------------------------- " << std::endl;
                std::cout << "\t\t\t|\tAjouter un nouveau contact\t |" << std::endl;
                std::cout << "\t\t\t ---------------------------------------- " << std::endl;

                std::string nom_contact;
                std::string numero_contact;
                std::string email_contact;
                std::string addr_contact;

                std::cout << " Entrer le nom du contact\t: ";
                std::getline(std::cin, nom_contact);

                std::cout << " Entrer le numero du contact\t: ";
                std::getline(std::cin, numero_contact);

                std::cout << " Entrer l'email du contact\t: ";
                std::getline(std::cin, email_contact);

                std::cout << " Entrer l'addresse' du contact\t: ";
                std::getline(std::cin, addr_contact);

                mes_contacts.ajouterContact(nom_contact, numero_contact, email_contact, addr_contact);

                system("pause");
                break;
            }
            case 3:{
                // Modefier un contact
                system("CLS");

                std::cout << "\t\t\t --------------------------------- " << std::endl;
                std::cout << "\t\t\t|\tModefier un contact\t |" << std::endl;
                std::cout << "\t\t\t --------------------------------- " << std::endl;

                std::string numero_contact;

                std::cout << "Entrer le numero du contact: ";
                std::getline(std::cin, numero_contact);

                mes_contacts.modiferContact(numero_contact);

                system("pause");
                break;
            }
            case 4:{
                // Supprimer un contact
                system("CLS");

                std::cout << "\t\t\t ---------------------------------- " << std::endl;
                std::cout << "\t\t\t|\tSupprimer un contact\t   |" << std::endl;
                std::cout << "\t\t\t ---------------------------------- " << std::endl;

                std::string numero_contact;
                
                std::cout << "Entrer le numero du contact: ";
                std::getline(std::cin, numero_contact);

                mes_contacts.supprimerContact(numero_contact);

                system("pause");
                break;
            }
                
            case 5:{
                // Chercher un contact
                system("CLS");

                std::cout << "\t\t\t --------------------------------- " << std::endl;
                std::cout << "\t\t\t|\tChercher un contact\t  |" << std::endl;
                std::cout << "\t\t\t --------------------------------- " << std::endl;

                mes_contacts.chercherContact();

                system("pause");
                break;
            }
            case 0:
                // exit
                system("CLS");
                
                mes_contacts.saveContacts();
                std::cout << "A bientot!" << std::endl;
                system("pause");
                break;
            default:
                std::cout << "Votre choix n'esiste pas dans notre menu !!!\n" << std::endl;
        }

    }while(option != 0);

    // save the data to a file
    return 0;
}

void afficherMenu(){
    std::cout << "\t\t\t\t ----------------------------------------------" << std::endl;
    std::cout << "\t\t\t\t|                     Menu                     |" << std::endl;
    std::cout << "\t\t\t\t ----------------------------------------------" << std::endl;
    std::cout << "\t\t\t\t|    1) Afficher tous les contacts             |" << std::endl;
    std::cout << "\t\t\t\t|    2) Ajouter un contact                     |" << std::endl;
    std::cout << "\t\t\t\t|    3) Modifier un contact                    |" << std::endl;
    std::cout << "\t\t\t\t|    4) Supprimer un contact                   |" << std::endl;
    std::cout << "\t\t\t\t|    5) Rechercher un contact                  |" << std::endl;
    std::cout << "\t\t\t\t|    0) Quitter                                |" << std::endl;
    std::cout << "\t\t\t\t ---------------------------------------------- \n" << std::endl;
}
