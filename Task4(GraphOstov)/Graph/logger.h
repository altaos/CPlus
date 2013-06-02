#ifndef LOGGER_H
#define LOGGER_H
#include <QFile>
#include <QTextStream>

class Logger
{
private:
    QFile* file;
    QTextStream* out;
public:
    Logger();
    ~Logger();

    void Write(QString string);
};

#endif // LOGGER_H
