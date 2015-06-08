#ifndef QRPGDATABASE_H
#define QRPGDATABASE_H

#include <QString>

namespace QRPGDao {

class QRPGProject;

class QRPGDatabase
{

public:
    virtual void closeProject() = 0;
    virtual QRPGProject *createNewProject(const QString &projectLocationURI, const QString &projectTitle, const QString &gameTitle) = 0;
    virtual QString info() const = 0; // Tells you what kind of Dao this is
    virtual QRPGProject *openDummyProject() = 0;
    virtual QRPGProject *openProjectDir(const QString &projectDirURI) = 0;

protected:
    QRPGProject *newProject(const QString &projectDirURI, const QString &projectTitle, const QString &gameTitle);
    void setProjectTileSize(QRPGProject *project, int tileSize);
};

enum DaoType
{
    FILE
};

QRPGDatabase *newDao();

} // namespace QRPGDao

#endif // QRPGDATABASE_H