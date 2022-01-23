#include "Magasin.h"


Magasin::Magasin(){

}


Magasin::Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders){
    m_products.reserve(products.size()); 
    for(auto& i : products) 
        m_products.push_back(&i); 

    m_clients.reserve(clients.size());
    for(auto& i : clients)
        m_clients.push_back(&i);
    
    m_orders.reserve(orders.size());
    for(auto& i : orders)
        m_orders.push_back(&i); 

}


Magasin::Magasin(std::vector <Product>& products){
    m_products.reserve(products.size()); 
    for(auto& i : products) 
        m_products.push_back(&i);

}


std::vector <Product* > Magasin::getProducts() const { return m_products ;}
std::vector <Client* > Magasin::getClients() const { return m_clients ;}
std::vector <Commande* > Magasin::getOrders() const { return m_orders ;}


void Magasin::addProduct(Product& product){
    m_products.push_back(&product) ;
}

void Magasin::addClient(Client& client){
    m_clients.push_back(&client) ;
}

void Magasin::addOrder(Commande& order){
    m_orders.push_back(&order) ;
}



void Magasin::updateQuantite(std::string nom_produit,int quantite){
    if(quantite >= 0){
        for(auto& i : m_products){
             if( i->getTitre() == nom_produit){
            i->setQuantite(quantite);
            break;
             }
        }
    }
    else 
        std::cout << "Erreur : quantité saisie est inférieure à 0 .\n";
}

void Magasin::addProductToStore(std::string nom, std::string description, float prix, int quantite){
    Product* produit = new Product(nom, description, prix, quantite);
    m_products.push_back(produit);
}

void Magasin::displayProduct(std::string nom_produit){
    for(auto& i : m_products)
        if( i->getTitre() == nom_produit){
            std::cout << "\nDetails of a product\n" ;
            std::cout << *i << "\n";
            break; 
        }
}

void Magasin::displayProducts(){
    std::cout << "\nProducts\n" ;
    std::cout << "Name" ;
    for(int i = 0 ; i < 15 - 4; i++)  //taille du champ total est 15 et la taille de Name est 4
        std::cout << " ";

    std::cout << "Description";
    for(int i = 0 ; i < 40 - 11 ; i++)  //taille du champ total est 15 et la taille de Description est 11
        std::cout << " ";        

    std::cout << "Quantity";
    for(int i = 0 ; i < 12 - 8; i++)  //taille du champ total est 10 et la taille de Quantity est 8
        std::cout << " ";      

    std::cout << "Price\n";    

//Affichage des produits
for(auto& i : m_products )
   std::cout << *i << std::endl;

std::cout << std::endl; 
}

void Magasin::addClient(std::string nom, std::string prenom){
    Client* client = new Client(nom,prenom);
    m_clients.push_back(client);
}


void Magasin::displayClients(){
    std::cout << "\nClients\n";
    std::cout << "Uid" ;
    for(int i = 0 ; i < 10 - 3; i++)  //taille du champ total est 10 et la taille de Uid est 3
        std::cout << " ";
    std::cout << "Identity\n";

    for(auto& i:m_clients){
        std::cout << i->getId() ;
        for(int j = 0 ; j < 10 - (int)std::to_string(i->getId()).length() ; j++)   
            std::cout << " ";
        std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;
    }
    std::cout << std::endl;
    
}

void Magasin::displayClient(std::string prenom, std::string nom){
    for(auto& i : m_clients){
        if( i -> getPrenom() == prenom || i->getNom() == nom){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int i = 0 ; i < 10 - 3; i++)  //taille du champ total est 10 et la taille de Uid est 3
                std::cout << " ";
            std::cout << "Identity\n";
            std::cout << i->getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i->getId()).length() - 3; j++)   
                std::cout << " ";
             std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;

            break; 
        }
    }
}

void Magasin::displayClient(int id){
    for(auto& i : m_clients){
        if ( i -> getId() == id){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int j = 0 ; j < 10 - 3; j++)  //taille du champ total est 10 et la taille de Uid est 3
                std::cout << " ";
            std::cout << "Identity\n";
            std::cout << i->getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i->getId()).length() - 3; j++)   
                std::cout << " ";
             std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;
            break; 
        }
    }
}

void Magasin::addProductToShoppingCart(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom ){
                    j -> addProduct(*i); 
                    break; 
                }
            break;
        }
}


void Magasin::addProductToShoppingCart(std::string titre, int id ){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id){
                    j -> addProduct(*i); 
                    break;           
                }  
             break; 
        }
}

void Magasin::deleteProductClient(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom){
                    j -> deleteProduct(titre);
                    break;               
                }
            break;}
}

void Magasin::deleteProductClient(std::string titre, int id){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id ){
                    j -> deleteProduct(titre);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, int id){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id ){
                    j->updateQuantity(titre, quantite);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom){
                    j->updateQuantity(titre, quantite);
                    break;
                }
            break;
        }  
}


bool Magasin::validationCommande(Client& client){
    bool valide = true ;
    for(auto& i:client.getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ 
                    valide = false;                    
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(client); 
        m_orders.push_back(commande); 
        for(auto& i :client.getPanier()) 
            for(auto& j: m_products)
                if(i.getTitre() == j->getTitre()){
                    int quantite_restee;
                    quantite_restee = j->getQuantite() - i.getQuantite();
                    j -> setQuantite(quantite_restee);
                }

        std::cout << "Commande validée" << std::endl;
        client.viderPanier(); 
    }

    else
        std::cout << "Commande non validée" << std::endl;
    
    return valide;
}


bool Magasin::validationCommande(std::string prenom, std::string nom){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    for(auto&i : m_clients)
        if(i->getPrenom() == prenom && i -> getNom() == nom ){
            client = i;
            client_trouve = true ;
            break;

    if(client_trouve)
    for(auto& i:client -> getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ 
                    valide = false;                       
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(*client); 
        m_orders.push_back(commande); 
        for(auto& i :client->getPanier()) 
            for(auto& j: m_products)
                if(i.getTitre() == j->getTitre()){
                    int quantite_restee;
                    quantite_restee = j->getQuantite() - i.getQuantite();
                    j -> setQuantite(quantite_restee);
                }

        std::cout << "Commande validée" << std::endl;
        client->viderPanier(); 
    }
    else if(!client_trouve)
        std::cout << "Commande non validée, client introuvable" << std::endl;
    
    return valide;
}
bool Magasin::validationCommande(int id){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    for(auto&i : m_clients)
        if(i->getId() == id ){
            client = i;
            client_trouve = true ;
            break; 
        }


    for(auto& i:client->getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ 
                    valide = false;                      
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(*client); 
        m_orders.push_back(commande); 
        std::cout << "Commande validée" << std::endl;
        client->viderPanier(); 
    }
    else if(!client_trouve)
        std::cout << "Commande non validée, client introuvable" << std::endl;
    
    return valide;
}


bool Magasin::updateCommandeStatus(int id , bool status){
    
    bool commande_trouvee = false;
    for(auto&i : m_orders)
        if(i->getId() == id ){
            i -> setLivraison(status); 
            commande_trouvee = true ;
            break; 
        }    
    
    if(commande_trouvee)
        std::cout << "Mise à jour du statut de la commande réussie\n";
    else
        std::cout << "Erreur: Mise à jour du statut de la commande échouée (commande introuvable)\n";

    return commande_trouvee ;   
}


void Magasin::affichageCommandePassees(){
    std::cout << "\t---Affichage des commandes passées---\n";
    for(auto& i : m_orders) 
        if(i->getLivraison()) 
            std::cout << *i << std::endl;
}


void Magasin::affichageCommandesClient(int id){
    std::cout << "\t---Affichage des commandes du client d'ID " << id << " ---\n";
    for(auto& i : m_orders)
        if( i->getClient()->getId() == id)
            std::cout << *i << std::endl;
}

void Magasin::affichageCommandesClient(std::string prenom, std::string nom){
    std::cout << "\t---Affichage des commandes du client " << prenom << " "<< nom << " ---\n";
    for(auto& i : m_orders)
        if( i->getClient()->getPrenom() == prenom && i->getClient()->getNom() == nom)
            std::cout << *i << std::endl;
}

bool Magasin::productExist(std::string titre){
    for(auto&i : m_products)
        if(i -> getTitre() == titre)
            return true;
    return false;
}

Product* Magasin::productFind(std::string titre){
    for(auto&i : m_products)
        if(i -> getTitre() == titre)
            return i;
    return nullptr;
}

bool Magasin::clientExist(std::string prenom, std::string nom){
    for(auto& i:m_clients)
        if( i -> getPrenom() == prenom && i-> getNom() == nom)
            return true ;

    return false ;
}


bool Magasin::clientExist(int id){
    for(auto& i:m_clients)
        if( i-> getId() == id)
            return true; 
    
    return false;
}


Client* Magasin::clientFind(std::string prenom , std::string nom){
    if(clientExist(prenom,nom)){
        for(auto& i:m_clients)
            if( i -> getPrenom() == prenom && i-> getNom() == nom)
                return i ;  
    } 
    
    else
        std::cout << "Erreur: client introuvable\n";
    
    return nullptr;
}