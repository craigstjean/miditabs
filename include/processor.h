#pragma once

#include <exception>
#include <fstream>

class FileError : public std::exception
{
public:
    FileError(const char *message)
        : m_message{message}
    {
    }

    virtual const char* what() const throw()
    {
        return m_message;
    }
private:
    const char *m_message;
};

class OpenFileError : public FileError
{
public:
    OpenFileError(const char *message)
        : FileError{message}
    {
    }
};

class Processor
{
public:
    Processor(const char *path)
        : stream(std::ifstream(path))
    {
        if (!stream)
        {
            throw OpenFileError(strerror(errno));
        }
    }

    ~Processor()
    {
        stream.close();
    }

    void execute();
private:
    std::ifstream stream;

    Processor(const Processor &);
    Processor & operator=(const Processor &);
};
