#ifndef FILES_CARE_H
#define FILES_CARE_H

#include <QObject>
#include <QStringList>

class Files_Care : public QObject
{
    Q_OBJECT
public:
    explicit Files_Care(QObject *parent = nullptr);

    QStringList getfoundFiles() const;

    void setFoundFiles(const QStringList &foundFiles);

private:
    QStringList foundFiles;

};

#endif // FILES_CARE_H
