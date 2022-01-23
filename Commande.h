#pragma once
#include "Customer.h"
#include <vector>
class Commande {
public:

    Commande();
    Commande(Client& client, bool livraison = false);


    void setClient(Client& client);
    void setLivraison(bool livraison);


    Client* getClient() const;
    std::vector<Product> getProduct() const;
    int getId() const;
    bool getLivraison() const;


    friend std::ostream& operator<< (std::ostream& output, Commande& commande);

private:
    Client* m_client;
    std::vector<Product> m_products;
    bool m_livraison; //true si la commande est livrée, sinon false
    int m_id;
    int identifiant_auto_int();
};