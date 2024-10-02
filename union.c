#include <unistd.h>

// int main(int argc, char **argv)
// {
//     int checker[255];
//     int i, j;

//     if (argc == 3)
//     {
//         i = 0;
//         while(i < 255)
//             checker[i++] = 0;
//         i = 1;
//         while (i < 3)
//         {
//             j = 0;
//             while (argv[i][j])
//             {
//                 if(!checker[(unsigned char)argv[i][j]]) 
//                 {
//                     checker[(unsigned char)argv[i][j]] = 1;
//                     write(1 ,&argv[i][j], 1);
//                 }
//                 j++;
//             }
//             i++;
//         }
//     }
//     write (1, "\n", 1);
// }

// int     main(int argc, char **argv)
// {
//     int checker[255];
//     int i, j;

//     if(argc == 3)
//     {
//         i = 0;
//         while (i < 255)
//             checker[i++] = 0;
//         i = 1;
//         while (i < 3)
//         {
//             j = 0;
//             while (argv[i][j])
//             {
//                 if (!checker[(unsigned int)argv[i][j]])
//                 {
//                     checker[(unsigned int)argv[i][j]] = 1;
//                     write (1, &argv[i][j], 1);
//                 }
//             j++;
//             }
//         i++;
//         }
//     }
//     write (1, "\n", 1);
// }



int    main(int argc, char **argv)
{
    int    i, j;
    int     checker[255];

    if(argc == 3) //nom du program = 1 , char recherche = 2, string dans laquelle je cherche = 3
    {
        i = 0;
        while (i < 255)
            checker[i++] = 0;
        i = 1;
        while (i < 3) // only checking arg 2 and 3
        {
            j = 0;
            while (argv[i][j])
            {
                if (!checker[(unsigned int)argv[i][j]])// if im not on what i look for 
                {
                    checker[(unsigned int)argv[i][j]] = 1;
                    write (1, &argv[i][j], 1);
          
                }
                j++;
            }
            i++;
        }
    }
    write (1, "\n", 1);
}
