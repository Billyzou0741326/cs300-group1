#include "person.h"

int main()
{
    provider test("kevin", 1234, "10293 OK road", "Portland", "OR", 92118, 120, 1239.22);

    test.display_provider_edit();


    cout << endl << endl;

    member test2("kevin", 1234, "10293 OK road", "Portland", "OR", 92118, false);

    test2.display_member_edit();



}
