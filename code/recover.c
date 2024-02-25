#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    //check arg
    if (argc != 2)
    {
        //error
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        return 1;
    }
    //creat byte
    typedef uint8_t BYTE;
    int num = 0;
    //buffer
    BYTE buff[512];
    //file pointer
    FILE *jp;
    //check blocks
    while (fread(buff, sizeof(BYTE), 512, card) == 512)
    {
        //if jpg
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            char name[8];
            //if first one
            if (num == 0)
            {
                //
                sprintf(name, "%03i.jpg", num);
                jp = fopen(name, "w");
                fwrite(buff, sizeof(BYTE), 512, jp);
                num++;
            }
            else
            {
                //if not
                fclose(jp);
                sprintf(name, "%03i.jpg", num);
                jp = fopen(name, "w");
                fwrite(buff, sizeof(BYTE), 512, jp);
                num++;
            }
        }
        else
        {
            if (num != 0)
            {
                fwrite(buff, sizeof(BYTE), 512, jp);
            }
        }
    }
}
