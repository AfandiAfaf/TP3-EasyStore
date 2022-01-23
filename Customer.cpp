#include "Client.h"

    Client::Client(){
        m_id = identifiant_auto_int();
    }

    Client::Client(std::string prenom, std::string nom, std::vector<Product> panier): m_prenom(prenom),
        m_nom(nom), m_panier(panier){
        m_id = identifiant_auto_int();
    }

    Client::Client(std::string prenom, std::string nom) :
        m_prenom(prenom), m_nom(nom){
                    m_id = identifiant_auto_int();
        }

    
    Client::Client(Client& client) : m_prenom(client.getPrenom()), m_nom(client.getNom()) {
        m_id = client.getId();

        m_panier.reserve(client.getPanier().size());
        for(auto& i : client.getPanier())
            m_panier.push_back(i) ;
    }

  
    std::string Client::getNom() const{ return m_nom;}
    std::string Client::getPrenom() const{ return m_prenom;}
    int Client::getId() const { return m_id;}
    std::vector<Product> Client::getPanier() const{return m_panier;}

    
    void Client::addProduct(Product produit , int quantite){
        m_panier.push_back(produit);
    }
    

    void Client::updateQuantity(Product produit,int quantite){
        for(int i =0 ; i< (int)m_panier.size() ; i++)
            if( m_panier.at(i).getTitre() == produit.getTitre()){
                m_panier.at(i).setQuantite(quantite);
                break;
            }
    }

    void Client::updateQuantity(std::string titre, int quantite){
        for(auto& i : m_panier)
            if( i.getTitre() == titre){
                i.setQuantite(quantite);
                break;
            }
    }

   
    void Client::viderPanier(){
        m_panier.erase(m_panier.begin(), m_panier.end()); 
    }

    
    void Client::deleteProduct(Product product){
        for(int i=0; i< (int)m_panier.size(); i++)
            if( (m_panier.at(i)).getTitre() == product.getTitre()){
                m_panier.erase(m_panier.begin()+i);
                break;
            }
    }
    
    void Client::deleteProduct(std::string titre){
        for(int i=0; i< (int)m_panier.size(); i++)
            if( (m_panier.at(i)).getTitre() == titre){
                m_panier.erase(m_panier.begin()+i);
                break;
            }
            
    }


 
    std::ostream& operator<< (std::ostream& output, Client& client){
    output << "ID(" << client.getId() << ") "<< client.getPrenom() << "\t" << client.getNom();
    output << "\n \tPanier:" ;
    for(int i=0 ; i< (int)client.m_panier.size();i++)
        output << "\n \t\t" << client.m_panier.at(i) ;
    output << "\n";

    return output;
    }

    int Client::identifiant_auto_int(){
        static int index=0;
	    index++ ;
	    return index;
    }