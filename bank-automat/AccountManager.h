#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QString>

class AccountManager
{
public:
    static AccountManager& getInstance() {
        static AccountManager instance; // Varmistaa, että instanssi luodaan vain kerran
        return instance;
    }

    AccountManager(const AccountManager&) = delete; // Poistaa kopio-konstruktorin
    AccountManager& operator=(const AccountManager&) = delete; // Poistaa sijoitusoperaattorin

    void setAccountId(const QString& id) {
        accountId = id;
    }


    QString getAccountId() const {
        return accountId;
    }


private:
    QString accountId; // Sisäinen muuttuja tilin ID:lle
    AccountManager() {} // Yksityinen konstruktori
};

#endif // ACCOUNTMANAGER_H
