#ifndef TAG_H
#define TAG_H
#include <string>
#include "ElementoTag.h"


using namespace std;

class Tag
{
public:
    Tag(string tag);
    ~Tag();


private:
    ElementoTag *primeiro;
    void InserirElemento(string a, string b);

};

#endif // TAG_H
