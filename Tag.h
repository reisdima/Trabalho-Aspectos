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

    void PrintTag();
    void CriarTag(string str);


private:
    ElementoTag *primeiro;
    void InserirElemento(string a, string b);

};

#endif // TAG_H
