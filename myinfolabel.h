#ifndef MYINFOLABEL_H
#define MYINFOLABEL_H

#include <QWidget>
#include "QHBoxLayout"
#include "QLabel"

namespace Ui {
class MyInfoLabel;
}

/**
 * @brief This class is a reued combination of two Labels to display Informations
 *
 */
class MyInfoLabel : public QHBoxLayout
{
    Q_OBJECT

public:
     /**
      * @brief This Constructor creates an instance of this class by giving it the Name and the Paramete as Strings.
      *
      * @param name the string to be displayed in the left Label commonly used as Name of the paramater and if once set not Changeable.
      * @param value the parameter itself in the right label. Changeable trough the setValue() function.
      */
     MyInfoLabel(QString name,QString value);
     /**
      * @brief This Constructor creates an instance of this class by giving it the Name as String. The Value can be changed via the setValue() function.
      *
      * @param name the string to be displayed in the left Label commonly used as Name of the paramater and if once set not Changeable.
      */
     MyInfoLabel(QString name);
    /**
     * @brief Destructor.
     *
     */
    ~MyInfoLabel();
    /**
     * @brief This function sets the value of the infoLabel as an String.
     *
     * @param value The value that gets displayed in the right label.
     */
    void setValue(QString value);
    /**
     * @brief This function sets the value of the infoLabel as an String.
     *
     * @param value The value that gets displayed in the right label.
     */
    void setValue(int value);
private:
     QLabel*valueName, *value; /**< TODO: describe */

};

#endif // MYINFOLABEL_H
