#ifndef CONTACTS_H_INCLUDED
#define CONTACTS_H_INCLUDED

#include <string>  // Pour utliser les chaines de caracteres
#include <algorithm>  // Manipuler les chaines de caracteres
#include <fstream>  // Travailler avec les fichiers

// Creer une classe Contacts
class Contacts {
    private:
        // Creer une liste chainee pour gerer les contacts
        typedef struct contactInfos {
            std::string full_name;  // Nom du contact
            std::string phone_number;  // Numero du contact
            std::string email;  // Adresse mail du contact
            std::string address;  // Adresse
            contactInfos* next;  // Pour la liste suivante
        }* contactPtr;

        // Pointeurs de contole
        contactPtr head;  // L'entree de la liste chainee
        contactPtr current;  // L'element actuel
        contactPtr temp;  // L'element precedent
    
    public:
        Contacts();
        // Methode pour ajouter un contact
        void ajouterContact(std::string c_name, std::string c_number, std::string c_email, std::string c_addr);
        // Methode pour modifier un contact
        void modiferContact(std::string number);
        // Methode pour supprimer un contact
        void supprimerContact(std::string number);
        // Methode pour afficher les contacts
        void afficherContacts();
        // Methode de recherche
        void chercherContact();
        // Methode pour sauvgarder les contacts dans un fichier text
        void saveContacts();
        // Methode pour rendre une chaine de characteres miniscules
        std::string lowerCaseName(std::string name);
};
#endif // CONTACTS_H_INCLUDED