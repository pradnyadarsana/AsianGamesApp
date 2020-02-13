//I KADEK HARYADI DARMAWAN 170709125
//CHRISTIAN VIERI PALEBANGAN 170709131
//PANDE NYOMAN PRADNYA DARSANA 170709153
//FENDY HERYANTO CHANDRA 170709218
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

typedef char string[50];

typedef struct tAtlet* adrAtlet;
typedef struct tNegara* adrNegara;
typedef struct tCabor* adrCabor;
typedef struct tNode* address;

typedef struct
{
	string kode;
	string nama;
	string kelamin;
	int usia;
}DataAtlet;

typedef struct
{
	string kodeNeg;
	string namaNeg;
	int emas;
	int perak;
	int perunggu;
}DataNegara;

typedef struct
{
	string kodeCab;
	string namaCab;
	string juara1;
	string juara2;
	string juara3;
}DataCabor;

typedef struct tAtlet
{
	DataAtlet A;
	adrAtlet nextAtlet;
}Atlet;

typedef struct tNegara
{
	DataNegara N;
	adrNegara nextNegara;
	adrAtlet firstAtlet;
}Negara;

typedef struct tCabor
{
	DataCabor C;
	adrCabor nextCabor;
	adrNegara firstNegara;
}Cabor;

typedef struct
{
	adrCabor first;
}ListCabor;

typedef struct tNode
{
	DataNegara N;
	address Next;
}Node;

typedef struct
{
	address first;
}List;


/////////FUNGSI LIST
void CreateEmpty(ListCabor *L);
int IsEmpty(ListCabor L);

/////////FUNGSI CABANG OLAHRAGA
int HaveNegara(adrCabor P);
adrCabor AlokasiCabor();
adrCabor FindCabor(ListCabor L, string kode);
DataCabor MakeDataCabor(string kodeCab, string namaCab);
int cekUnikKodeCabor(ListCabor L, string kodeCab);
int cekUnikNamaCabor(ListCabor L, string namaCab);
void insertFirstCabor(ListCabor *L, DataCabor C);
void insertLastCabor(ListCabor *L, DataCabor C);
void deleteFirstCabor(ListCabor *L);
void deleteAtCabor(ListCabor *L, string kodeCabor);
void EditDataCabor(adrCabor P, string kodeCab, string namaCab);
void printCabor(ListCabor L);
void PrintCaborbyNegara(ListCabor L, string kodeNeg);

///////////FUNGSI NEGARA
adrNegara AlokasiNegara(DataNegara N);
int HaveAtlet(adrNegara Q);
adrNegara FindNegara(adrCabor C, string kodeNeg);
DataNegara MakeDataNegara(string kodeNeg, string namaNeg);
int cekUnikNamaNegara(adrCabor P, string namaNeg);
int cekUnikKodeNegara(adrCabor P, string kodNeg);
int cekNamaNegara(ListCabor L, adrCabor P, string namaNeg);
void copyKodeNegara(ListCabor L, adrCabor P, string namaNeg, string kodeNeg);
void insertFirstNegara(adrCabor P, DataNegara N);
void insertLastNegara(adrCabor P, DataNegara N);
void DeleteFirstNegara(adrCabor P);
void DeleteAtNegara(ListCabor L, List *LT, adrCabor P, string kodeNegara);
void EditNegara(adrNegara Q, string namaNeg, string kodeNeg);
void PrintNegara(adrNegara Q);
void PrintCabordanNegara(ListCabor L);


///////////FUNGSI ATLET
adrAtlet AlokasiAtlet(DataAtlet A);
adrAtlet FindAtlet(adrNegara Q, string kode);
DataAtlet MakeDataAtlet(string kodeAlt, string nama, string kelamin, int usia);
int cekUnikKodeAtlet(adrNegara Q, string kodeAlt);
void insertFirstAtlet(adrNegara Q, DataAtlet A);
void insertLastAtlet(adrNegara Q, DataAtlet A);
void DeleteFirstAtlet(adrNegara Q);
void DeleteAtAtlet(adrNegara Q, string kode);
void EditAtlet(adrAtlet R, string kodeAlt, string nama, string kelamin, int usia);
void PrintAtlet(adrAtlet R);
void PrintAllAtletbyNegara(ListCabor L, string kodeNeg);
void PrintNegaradanAtlet(adrNegara Q);
void PrintNegaraAtletbyCabor(ListCabor L);
void PrintAll(ListCabor L);

//////////////FUNGSI LIST TAMPUNG
void HitungMendali(List LT, ListCabor L);
void BubbleSort(List LT);
void ShowRanking(List LT);
int cekNamaNegaraListTemp(List LT,string namaNeg);
void insertLast(List *LT, DataNegara C);
int hapusnegaramedali(ListCabor L, string kodeNeg);
void initmedali(List *LT);
void DeleteFirstNegaraMedali(List *LT);
void hapusNegaraMedali(List *LT, string kodeNeg);
