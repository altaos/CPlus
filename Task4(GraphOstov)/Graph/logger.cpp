#include "logger.h"

Logger::Logger()
{
    file = new QFile("log.txt");
    file->open(QIODevice::WriteOnly|QIODevice::Append);
    out = new QTextStream(file);
}

Logger::~Logger()
{
    if(out)
        delete out;

    if(file)
    {
        file->close();
        delete file;
    }
}

void Logger::Write(QString str)
{
    *out << str << "\n";
}
