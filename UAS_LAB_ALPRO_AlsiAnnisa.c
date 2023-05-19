#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100

struct Book {
char title[MAX_TITLE_LENGTH];
char publisher[100];
char author[100];
int numPages;
int isBorrowed;
};

void searchBook(struct Book books[], int numBooks, const char* searchTitle) {
int found = 0;
for (int i = 0; i < numBooks; i++) {
if (strcmp(books[i].title, searchTitle) == 0) {
printf("Buku ditemukan!\n");
printf("Judul: %s\n", books[i].title);
printf("Penerbit: %s\n", books[i].publisher);
printf("Pengarang: %s\n", books[i].author);
printf("Jumlah halaman: %d\n", books[i].numPages);

        if (books[i].isBorrowed) {
            printf("Status: Sedang dipinjam\n");
        } else {
            printf("Status: Tersedia\n");
        }

        found = 1;
        break;
    }
}

if (!found) {
    printf("Buku tidak ditemukan.\n");
}
}

void borrowBook(struct Book books[], int numBooks, const char* searchTitle) {
int found = 0;
for (int i = 0; i < numBooks; i++) {
if (strcmp(books[i].title, searchTitle) == 0) {
if (books[i].isBorrowed) {
printf("Buku sedang dipinjam dan tidak tersedia untuk dipinjamkan.\n");
} else {
books[i].isBorrowed = 1;
printf("Buku berhasil dipinjam.\n");
}
found = 1;
break;
}
}

if (!found) {
    printf("Buku tidak ditemukan.\n");
}
}

void returnBook(struct Book books[], int numBooks, const char* searchTitle) {
int found = 0;
for (int i = 0; i < numBooks; i++) {
if (strcmp(books[i].title, searchTitle) == 0) {
if (books[i].isBorrowed) {
books[i].isBorrowed = 0;
printf("Buku berhasil dikembalikan.\n");
} else {
printf("Buku tidak sedang dipinjam.\n");
}
found = 1;
break;
}
}

if (!found) {
    printf("Buku tidak ditemukan.\n");
}
}

int main() {
struct Book books[MAX_BOOKS] = {
{"DARK TWILIGHT","No Moore","DIVA Press",2012,250},
{"The Spell Bound Book","Miki Monticelli","Puspa Storia", 2009,300},
{"Outcast of Pride","Maximilian Surjadi","de TEENS",2016, 233},
{"THE APUILAS GHILD","Ruwi Meita","de TEENS",2019,350},
{"Reload of The Death","Rudiyanto", "KUNCI AKSARA",2014,240},
{"Night Flights","Philip Reeve","Noura Publishing",2012, 288},
{"Cinderella Journey","Shin Min Young","Zettu",2012,290},
{"Dead Girl Walking","Linda Joy Singleton","Atria",2003,422},
{"Cinta Pemuda Harimau","Sepriyossa Darmawan","Bintang Pertiwi Publishing",2008,356},
{"THE TOUCH","Daniel Kayes","Ufuk Publishing House",2005, 370},
{"Guardian Cheonsa","Karina Citra Ayu","PING!!!",2006,390},
{"The Wishsong of Shannara","Terry Brooks","The Random House Publishing Group",2013,320},
{"The Marvelous Land of Oz","L. Frank Baum","Serambi Ilmu Semesta",2017,300},
{"Witch Song","Amber Argyle","Atria",2019,380},
{"Magic Bleeds","Ilona Andrews","Ace Books",2020,298},
{"CINCIN SEMERAH DARAH","Jojo Alexander","Jogja Great! Publisher",2013,400},
{"NEGERI TANPA PERASAAN","Alanda Kariza ","Ufuk Press ",2015,370},
{"Pacar Hantu","Agung Waskito","Gallery Ilmu",2018,355},
{"HALO","Alexandra Adornetto","PT. Ufuk Puslishing House",2019,345},
{"The Virgin Suicides","Jeffrey Eugenides","Warner Books",2017,375},
{"TALES OF TERROR AND MYSTERY","Sir Arthut Conan Doyle","Kawah Media",2014,382},
{"DETEKTIF SEKOLAH","Dimas Abi","BUKUNE",2016,150},
{"Suara Waktu", "Mochtar Pobottinggi", "Erlangga",2019,283},
{"Menggugat Penguasa","Dhurorudin Mashad","Erlangga",2016,251},
{"MERINTIS RI YANG MANUSIAWI","Y.B. Mangunwijaya","Erlangga", 2013,249},
{"Metodologi Penelitian & Teknik Penyusunan Skripsi","H. Abdurrahmat Fathoni","PT. Rineka Cipta",2006,208},
{"Memahami Film","Himawan Pratists","Homerian Pustaka", 2008, 223},
{"Agar Menulis-Mengarang Bisa Gampang","Andrias Harefa","PT. Gramedia Pustaka Utama",2010,103},
{"Pengantar Filsafat Pendidikan","Drs. Uyoh sadulloh","PT.Gramedia",2004,183},
{"Tips & Trik Jago Main Rubik","Wicaksono Hadi","Gradien Mediatama",2013,184},
{"Cewek Smart","Ria Fariana","Gema Insani",2008,200},
{"TUILET","POben Cedric","Gradien Mediatama",2009,187},
{"Dear Nathan","Erisca Febrianti","Best Media",2016,528},
{"Perahu Kertas","Dewi Lestari (Dee)","Treudee Pustaka Sejati",2010,444},
{"Koala Kumal","Raditya Dika","Gagas Media",2015,200},
{"Rindu","Darwis Tere Liye","Republika",2014,300},
{"Satwa Terancam Bahaya","Jen Green","Pakar Raya",2019,32},
{"Sains dan Teknologi(Berbagai Ide untuk Menjawab Tantangan dan Kebutuhan)","Ristek","PT. Gramedia Pustaka Utama",2019,362},
{"Pantai dan Kehidupannya","Edy Karso","PT. INDAHJAYA Adipratama",2003,64},
{"Negeri 5 Menara","Ahmad Fuadi","PT. Gramedia Pustaka Utama", 2009,600},
{"Keanekaragaman Flora & Fauna","Suripno","Pakar Raya",2006,320},
{"Cerita Rayat Nusantara 1","Tim Erlangga For Kids","Erlangga",2016,67},
{"Bicaralah Cintaku","Andin","Republika",2011,90},
{"Rembulan Bersinar Diwajahmu","Tere Liye","Republika",2009,426},

{"Logika Dan Himpunan","Drs. Sukirman M.Pd","Hanggar Kreator",2006,207},
{"Algoritma & Pemrograman dengan C++","Andri Kristanto","Graha Ilmu",2013,253},
{"Remaja Membangun Kepribadian","Anna Windyartini S.","Nobel Edumedia",2008,79},
{"The Magic Smile","Athif AbulId","PT.Gratama",2018,108},
{"Saya Pengen jadi Creative Director","Budiman Hakim",2019,186},
{"Indonesia Cerdas","widyanto","Galangpress",2016,400},
{"Pemenang Ahmad Saiful Islam","aryanto","Elex Media Komputindo",2013,202},
};
int numBooks = MAX_BOOKS;

int choice;
char searchTitle[MAX_TITLE_LENGTH];

printf("=====================================================================\n");
printf("\t   SELAMAT DATANG DI PERPUSTAKAAN WILAYAH PROV.JAWA BARAT \n");
printf("=====================================================================\n");
printf("Silahkan Masukkan Data Diri Anda \n");

char nama;
int nomor_anggota;

printf("Masukkan Nama Anda: ");
scanf("%[^\n]", &nama);
printf("Masukkan Nomor Anggota: ");
scanf("%d", &nomor_anggota);
printf("=====================================================================\n");
printf("------------------------------Daftar Buku----------------------------\n");
printf("=====================================================================\n");
printf("1.Metodologi Penelitian & Teknik Penyusunan Skripsi\n");
printf("2.Memahami Film\n");
printf("3.Agar Menulis-Mengarang Bisa Gampang\n");
printf("4.Pengantar Filsafat Pendidikan\n");
printf("5.Tips & Trik Jago Mian Rubik\n");
printf("6.Cewek Smart\n");
printf("7.TUILET\n");
printf("8.Dear Nathan\n");
printf("9.Perahu Kertas\n");
printf("10.Koala Kumal\n");
printf("11.Rindu\n");
printf("12.Satwa Terancam Bahaya\n");
printf("13.Sains & Teknologi, berbagai Ide Untuk Menjawab Tantangan & Kebutuhan\n");
printf("14.Pantai & Kehidupannya\n");
printf("15.Negeri 5 Menara\n");
printf("16.Aljabar Linear Elementer\n");
printf("17.Cerita Rakyat Nusantara 1\n");
printf("18.Bicaralah Cintaku\n");
printf("19.Rembulan Bersinat di Wajahmu\n");
printf("20.Logika & Himpunan\n");
printf("21.Algoritma & Pemrograman\n");
printf("22.Remaja Membangun Kepribadian\n");
printf("23.The Magic Smile (SENYUM)\n");
printf("24.Saya Pengen Jadi Creative Director\n");
printf("25.Pemenang Diatas Pemenang\n");
printf("26.Dark Twilight\n");
printf("27.The Spell Bound Book\n");
printf("28.Outcast Of Pride\n");
printf("29.The Apuila Ghild\n");
printf("30.Reload Of The Death\n");
printf("31.Nights Flights\n");
printf("32.Cinderella Journey\n");
printf("33.Dead Girl Walking\n");
printf("34.Cinta Pemuda Harimau\n");
printf("35.The Touch\n");
printf("36.Guardian Cheonsa\n");
printf("37.The Wishong pf Shannara\n");
printf("38.The Marvelous Land Of Oz\n");
printf("39.Witch Song\n");
printf("40.Magic Bleeds\n");
printf("41.Cincin Semerah Darah\n");
printf("42.Negeri Tanpa Perasaan\n");
printf("43.Pacar Hantu\n");
printf("44.HALO\n");
printf("45.The Virgin Suicides\n");
printf("46.Tales Of Terror & Mystery\n");
printf("47.Detektif Sekolah\n");
printf("48.Suara Waktu\n");
printf("49.Menggugat Penguasa\n");
printf("50.Merintis RI Yang Manusiawi\n");
do {
    printf("\n===== MENU =====\n");
    printf("1. Cari buku\n");
    printf("2. Pinjam buku\n");
    printf("3. Kembalikan buku\n");
    printf("4. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);
    getchar(); // Membaca karakter newline setelah memasukkan pilihan menu

    switch (choice) {
        case 1:
            printf("\nMasukkan judul buku yang ingin dicari: ");
            fgets(searchTitle, sizeof(searchTitle), stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';
            searchBook(books, numBooks, searchTitle);
            break;
        case 2:
            printf("\nMasukkan judul buku yang ingin dipinjam: ");
            fgets(searchTitle, sizeof(searchTitle), stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';
            borrowBook(books, numBooks, searchTitle);
            break;
        case 3:
            printf("\nMasukkan judul buku yang ingin dikembalikan: ");
            fgets(searchTitle, sizeof(searchTitle), stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';
            returnBook(books, numBooks, searchTitle);
            break;
        case 4:
            printf("\nTerima kasih telah menggunakan program ini. Sampai jumpa!\n");
            break;
        default:
            printf("\nPilihan menu tidak valid. Silakan coba lagi.\n");
            break;
    }
} while (choice != 4);

return 0;
}
