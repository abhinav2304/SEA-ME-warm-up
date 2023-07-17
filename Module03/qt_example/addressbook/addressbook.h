#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "finddialog.h"

#include <QWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
QT_END_NAMESPACE

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = nullptr);
    enum Mode { NavigationMode, AddingMode, EditingMode };
    ~AddressBook();

public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();

    void editContact();
    void removeContact();
    void updateInterface(Mode mode);

    void findContact();

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *editButton;
    QPushButton *removeButton;

    QPushButton *findButton;

    QMap<QString, QString> contacts;
    QString oldName;
    QString oldAddress;

    Mode currentMode;
    FindDialog *dialog;
};
#endif // ADDRESSBOOK_H
