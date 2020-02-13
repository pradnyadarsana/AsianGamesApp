#include "header.h"

//////FUNGSI LIST
void CreateEmpty(ListCabor *L)
{
	(*L).first=NULL;
}

int IsEmpty(ListCabor L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;
}

////////FUNGSI CABANG OLAHRAGA
int HaveNegara(adrCabor P)
{
	if(P->firstNegara!=NULL)
		return 1;
	else
		return 0;
}

adrCabor AlokasiCabor(DataCabor C)
{
	adrCabor P;
	
	P = (adrCabor) malloc(sizeof(Cabor));
	P->C=C;
	P->nextCabor=NULL;
	P->firstNegara=NULL;
	
	return P;
}

adrCabor FindCabor(ListCabor L, string kode)
{
	adrCabor P=L.first;
	
	while(P!=NULL && strcmpi(P->C.kodeCab,kode)!=0)
	{
		P=P->nextCabor;
	}
	return P;
}

DataCabor MakeDataCabor(string kodeCab, string namaCab)
{
	DataCabor C;
	strcpy(C.kodeCab,kodeCab);
	strcpy(C.namaCab,namaCab);
	strcpy(C.juara1,"kosong");
	strcpy(C.juara2,"kosong");
	strcpy(C.juara3,"kosong");
	return C;
}

int cekUnikKodeCabor(ListCabor L, string kodeCab)
{
	adrCabor P; 
	P  = L.first;
	if(IsEmpty(L)!=1){
		while(P != NULL)
		{
			if(strcmpi(P->C.kodeCab,kodeCab)==0){
				return 0;
			}
			P = P->nextCabor;
		}
		return 1;	
	}
	else
		return 1;
}

int cekUnikNamaCabor(ListCabor L, string namaCab)
{
	adrCabor P; 
	P  = L.first;
	if(IsEmpty(L)!=1){
		while(P != NULL)
		{
			if(strcmpi(P->C.namaCab,namaCab)==0){
				return 0;
			}
			P = P->nextCabor;
		}
		return 1;	
	}
	else
		return 1;
}

void insertFirstCabor(ListCabor *L, DataCabor C)
{
	adrCabor P;
	P=AlokasiCabor(C);
	P->nextCabor=(*L).first;
	(*L).first=P;
	printf("\nData Cabor Berhasil Dimasukkan!");
}

void insertLastCabor(ListCabor *L, DataCabor C)
{
	adrCabor P, last;
	if(IsEmpty(*L))
		insertFirstCabor(&(*L), C);
	else{
		P=AlokasiCabor(C);
		last = (*L).first;
		while(last->nextCabor!=NULL)
		{
			last=last->nextCabor;
		}
		last->nextCabor=P;
		printf("\nData Cabor Berhasil Dimasukkan!");
	}
}

void deleteFirstCabor(ListCabor *L)
{
	adrCabor del;
	if(IsEmpty(*L))
		printf("List Kosong...");
	else
	{
		del = (*L).first;
		(*L).first = (*L).first->nextCabor;
		free(del);
		printf("\nData Cabor Berhasil Dihapus!");
	}
}

void deleteAtCabor(ListCabor *L, string kodeCabor)
{
	adrCabor del, cari;
	del = FindCabor((*L), kodeCabor);
	
	if(del==NULL)
		printf("\n\n\tData tidak ditemukan...");
	else
	{
		if(del==(*L).first)
			deleteFirstCabor(&(*L));
		else
		{
			cari=(*L).first;
			while(cari!=NULL && cari->nextCabor!=del)
			{
				cari=cari->nextCabor;
			}
			cari->nextCabor = del->nextCabor;
			free(del);
			printf("\nData Cabor Berhasil Dihapus!");
		}
	}
}

void EditDataCabor(adrCabor P, string kodeCab, string namaCab)
{
	strcpy(P->C.kodeCab,kodeCab);
	strcpy(P->C.namaCab,namaCab);
}

void printCabor(ListCabor L)
{
	adrCabor P;
	
	if(IsEmpty(L))
		printf("\nList Kosong...");
	else
	{
		P=L.first;
		while(P!=NULL)
		{
			printf("\nCabang olahraga: %s",P->C.namaCab);
			printf("\nKode Cabang Olahraga: %s",P->C.kodeCab);
			printf("\n=====================================");
			P=P->nextCabor;
		}
	}
}

void PrintCaborbyNegara(ListCabor L, string kodeNeg)
{
	adrCabor P;
	adrNegara Q;
	int i=0;
	
	if(IsEmpty(L))
		printf("\nList Kosong...");
	else
	{
		P=L.first;
		while(P!=NULL)
		{			
			if(HaveNegara(P))
			{
				Q=FindNegara(P, kodeNeg);
				if(Q!=NULL)
				{
					if(i==0)
					{
						printf("\n============================");
						printf("\nKode Negara : %s",Q->N.kodeNeg);
						printf("\nNama Negara : %s",Q->N.namaNeg);
						printf("\n============================\n");
						i=1;
					}
					printf("\nKode Cabor : %s",P->C.kodeCab);
					printf("\nNama Cabor : %s",P->C.namaCab);
				}
			}			
			P=P->nextCabor;
		}
	}
}

////////FUNGSI Negara
adrNegara AlokasiNegara(DataNegara N)
{
	adrNegara Q;
	
	Q = (adrNegara) malloc(sizeof(Negara));
	Q->N=N;
	Q->nextNegara=NULL;
	Q->firstAtlet=NULL;
	return Q;
}

int HaveAtlet(adrNegara Q)
{
	if(Q->firstAtlet!=NULL)
		return 1;
	else
		return 0;
}

adrNegara FindNegara(adrCabor C, string kodeNeg)
{
	adrNegara Q=C->firstNegara;
	
	while(Q!=NULL && strcmpi(Q->N.kodeNeg,kodeNeg)!=0)
	{
		Q=Q->nextNegara;
	}
	return Q;
}

DataNegara MakeDataNegara(string kodeNeg, string namaNeg)
{
	DataNegara N;
	strcpy(N.kodeNeg,kodeNeg);
	strcpy(N.namaNeg,namaNeg);
	N.emas=0;
	N.perak=0;
	N.perunggu=0;
	return N;
}

int cekUnikNamaNegara(adrCabor P, string namaNeg)
{
	adrNegara Q; 
	Q  = P->firstNegara;
	if(Q!=NULL){
		while(Q != NULL)
		{
			if(strcmpi(Q->N.namaNeg,namaNeg)==0){
				return 0;
			}
			Q = Q->nextNegara;
		}
		return 1;	
	}
	else
		return 1;
}

int cekUnikKodeNegara(adrCabor P, string kodeNeg)
{
	adrNegara Q; 
	Q  = P->firstNegara;
	if(Q!=NULL){
		while(Q != NULL)
		{
			if(strcmpi(Q->N.kodeNeg,kodeNeg)==0){
				return 0;
			}
			Q = Q->nextNegara;
		}
		return 1;	
	}
	else
		return 1;
}

int cekNamaNegara(ListCabor L, adrCabor P, string namaNeg)
{
	adrNegara Q;
	adrCabor bantu;
	
	bantu=L.first; 
	if(bantu!=NULL)
	{
		while(bantu!=NULL)
		{
			if(bantu!=P)
			{
				Q = bantu->firstNegara;
				while(Q != NULL)
				{
					if(strcmpi(Q->N.namaNeg,namaNeg)==0){
						return 0;
					}
					Q = Q->nextNegara;
				}
			}
			bantu = bantu->nextCabor;
		}
		return 1;
	}
	return 1;
}

void copyKodeNegara(ListCabor L, adrCabor P, string namaNeg, string kodeNeg)
{
	adrNegara Q;
	adrCabor bantu;
	
	bantu = L.first; 
	if(bantu!=NULL)
	{
		while(bantu!=NULL)
		{
			if(bantu!=P)
			{
				Q =  bantu->firstNegara;
				while(Q != NULL)
				{
					if(strcmpi(Q->N.namaNeg,namaNeg)==0){
						strcpy(kodeNeg,Q->N.kodeNeg);
						break;
					}
					Q = Q->nextNegara;
				}
			}
			bantu = bantu->nextCabor;
		}
	}
}

void insertFirstNegara(adrCabor P, DataNegara N)
{
	adrNegara Q;
	
	Q=AlokasiNegara(N);
	
	Q->nextNegara=P->firstNegara;
	P->firstNegara=Q;
}

void insertLastNegara(adrCabor P, DataNegara N)
{
	adrNegara Q, LastNegara;

	if(!HaveNegara(P))
		insertFirstNegara(P, N);
	else
	{
		Q=AlokasiNegara(N);
		LastNegara = P->firstNegara;
		while(LastNegara->nextNegara!=NULL)
		{
			LastNegara=LastNegara->nextNegara;
		}
		LastNegara->nextNegara= Q;
	}
}

void DeleteFirstNegara(adrCabor P)
{
	adrNegara del;
	
	if(!HaveNegara(P))
		printf("Tidak ada Negara");
	else
	{
		del = P->firstNegara;
		P->firstNegara=P->firstNegara->nextNegara;
		free(del);
		printf("\nData Negara Berhasil Dihapus!");
	}
}

void DeleteAtNegara(ListCabor L, List *LT, adrCabor P, string kodeNegara)
{
	adrNegara del, cari;
	int count=0;
	
	del = FindNegara(P, kodeNegara);
	if(del==NULL)
	{
		printf("Data negara tidak ditemukan...");
	}else
	{
		count=hapusnegaramedali(L, kodeNegara);
		
			if(count==1)
			{
				hapusNegaraMedali(&(*LT), kodeNegara);
			}
		if(del==P->firstNegara)
			DeleteFirstNegara(P);
		else
		{
			cari=P->firstNegara;
			while(cari!=NULL && cari->nextNegara!=del)
			{
				cari=cari->nextNegara;
			}
			cari->nextNegara = del->nextNegara;
			free(del);
			printf("Berhasil dihapus");
		}
	}	
}

void EditNegara(adrNegara Q, string namaNeg, string kodeNeg)
{
	strcpy(Q->N.namaNeg,namaNeg);
	strcpy(Q->N.kodeNeg,kodeNeg);
}

void PrintNegara(adrNegara Q)
{
	if(Q!=NULL)
	{
		while(Q!=NULL)
		{
			printf("\n\tKode Negara		:%s",Q->N.kodeNeg);
			printf("\n\tNama Negara		:%s",Q->N.namaNeg);
			printf("\n\t========================");
			Q=Q->nextNegara;
		}
	}
}

void PrintCabordanNegara(ListCabor L)
{
	adrCabor P;
	adrNegara Q;
	string cabor;
	
	if(IsEmpty(L))
		printf("\nList Kosong...");
	else
	{
		printf("\n\nMasukan Kode Cabor : ");fflush(stdin);gets(cabor);
		P=FindCabor(L, cabor);
		if(P!=NULL)
		{
			printf("\n\nKode Cabor : %s",P->C.kodeCab);
			printf("\nNama Cabor : %s",P->C.namaCab);
			printf("\n==============================");				
			if(HaveNegara(P)==0)
			{
				printf("\nBelum ada Negara yang Berpartisipasi");
				printf("\n=======================================");
			}else
			{
				Q=P->firstNegara;
				PrintNegara(Q);
			}	
		}else
		{
			printf("Cabor tidak ditemukan!");
		}
	}
}



////////FUNGSI Atlet
adrAtlet AlokasiAtlet(DataAtlet A)
{
	adrAtlet R;
	
	R = (adrAtlet) malloc(sizeof(Atlet));
	R->A=A;
	R->nextAtlet=NULL;
	return R;
}

adrAtlet FindAtlet(adrNegara Q, string kode)
{
	adrAtlet R=Q->firstAtlet;
	
	while(R!=NULL && strcmpi(R->A.kode,kode)!=0)
	{
		R=R->nextAtlet;
	}
	return R;
}

int cekUnikKodeAtlet(adrNegara Q, string kodeAlt)
{
	adrAtlet R; 
	R  = Q->firstAtlet;
	if(R!=NULL){
		while(R != NULL)
		{
			if(strcmpi(R->A.kode,kodeAlt)==0){
				return 0;
			}
			R = R->nextAtlet;
		}
		return 1;	
	}
	else
		return 1;
}

DataAtlet MakeDataAtlet(string kodeAlt, string nama, string kelamin, int usia)
{
	DataAtlet A;
	
	strcpy(A.kode,kodeAlt);
	strcpy(A.nama,nama);
	strcpy(A.kelamin,kelamin);
	A.usia=usia;
	
	return A;
}

void insertFirstAtlet(adrNegara Q, DataAtlet A)
{
	
	adrAtlet R;
	R=AlokasiAtlet(A);
	R->nextAtlet=Q->firstAtlet;
	Q->firstAtlet=R;
}

void insertLastAtlet(adrNegara Q, DataAtlet A)
{
	adrAtlet R, LastAtlet;
	
	if(HaveAtlet(Q)==0)
	{
		insertFirstAtlet(Q,A);
	}else
	{
		R=AlokasiAtlet(A);
		LastAtlet=Q->firstAtlet;
		while(LastAtlet->nextAtlet!=NULL)
		{
			LastAtlet=LastAtlet->nextAtlet;
		}
		LastAtlet->nextAtlet=R;
	}
}

void DeleteFirstAtlet(adrNegara Q)
{
	adrAtlet del;
	
	if(HaveAtlet(Q)==0)
	{
		printf("Negara ini tidak mempunyai atlet");
	}else
	{
		del=Q->firstAtlet;
		Q->firstAtlet=Q->firstAtlet->nextAtlet;
		free(del);
		printf("\nData Atlet Berhasil Dihapus!");
	}
}

void DeleteAtAtlet(adrNegara Q, string kode)
{
	adrAtlet del, bantu;
	
	if(HaveAtlet(Q)==0)
	{
		printf("Negara ini tidak mempunyai atlet");
	}else
	{
		del=FindAtlet(Q,kode);
		if(del!=NULL)
		{
			if(del==Q->firstAtlet)
				DeleteFirstAtlet(Q);
			else
			{
				bantu=Q->firstAtlet;
				while(bantu!=NULL && bantu->nextAtlet!=del)
				{
					bantu=bantu->nextAtlet;
				}
				bantu->nextAtlet=del->nextAtlet;
				free(del);
				printf("\nData Atlet Berhasil Dihapus!");
			}
		}else
		printf("Atlet tidak di temukan");
	}	
}

void EditAtlet(adrAtlet R, string kodeAlt, string nama, string kelamin, int usia)
{
	strcpy(R->A.kode,kodeAlt);
	strcpy(R->A.nama,nama);
	strcpy(R->A.kelamin,kelamin);
	R->A.usia=usia;
}

void PrintAtlet(adrAtlet R)
{
	if(R!=NULL)
	{
		while(R!=NULL)
		{
			printf("\n\t\tkode Atlet	:%s",R->A.kode);
			printf("\n\t\tNama Atlet	:%s",R->A.nama);
			printf("\n\t\tJenis Kelamin Atlet	:%s",R->A.kelamin);
			printf("\n\t\tTinggi Usia	:%d",R->A.usia);
			printf("\n\t\t========================");
			R=R->nextAtlet;
		}
	}
}

void PrintAllAtletbyNegara(ListCabor L, string kodeNeg)
{
	adrCabor P;
	adrNegara Q;
	adrAtlet R;
	int i=0;
	
	if(IsEmpty(L))
		printf("\nList Kosong...");
	else
	{
		P=L.first;
		while(P!=NULL)
		{			
			if(HaveNegara(P))
			{
				Q=FindNegara(P, kodeNeg);
				if(Q!=NULL)
				{
					if(i==0)
					{
						printf("\n============================");
						printf("\nKode Negara : %s",Q->N.kodeNeg);
						printf("\nNama Negara : %s",Q->N.namaNeg);
						printf("\n============================\n");
						i=1;
					}
					if(HaveAtlet(Q))
					{
						printf("\nKode Cabor : %s",P->C.kodeCab);
						printf("\nNama Cabor : %s",P->C.namaCab);
						printf("\n==============================");
						R=Q->firstAtlet;
						PrintAtlet(R);
					}
				}
			}			
			P=P->nextCabor;
		}
	}
}

void PrintNegaradanAtlet(adrNegara Q)
{
	adrAtlet R;
	
	if(Q!=NULL)
	{
		while(Q!=NULL)
		{
			printf("\n\tKode Negara		:%s",Q->N.kodeNeg);
			printf("\n\tNama Negara		:%s",Q->N.namaNeg);
			printf("\n\t========================");
			if(HaveAtlet(Q)==0)
			{
				printf("\n\tNegara ini tidak Mempunyai Atlet");
				printf("\n\t===================================");
			}else
			{
				R=Q->firstAtlet;
				PrintAtlet(R);
			}
			Q=Q->nextNegara;
		}
	}
}

void PrintNegaraAtletbyCabor(ListCabor L)
{
	adrCabor P;
	adrNegara Q;
	string cabor;
	
	if(IsEmpty(L))
		printf("\nList Kosong...");
	else
	{
		printf("\nMasukan Cabor : ");fflush(stdin);gets(cabor);
		P=FindCabor(L, cabor);
		if(P!=NULL)
		{
			printf("=");
			printf("=");
			printf("=");
			printf("\n\nKode Cabor : %s",P->C.kodeCab);
			printf("\nNama Cabor : %s",P->C.namaCab);
			printf("\n==============================");				
			if(HaveNegara(P)==0)
			{
				printf("\nBelum ada Negara yang Berpartisipasi");
				printf("\n======================================");
			}else
			{
				Q=P->firstNegara;
				PrintNegaradanAtlet(Q);
			}
		}else
			printf("\nCabor tidak terdaftar!");
	}
}

void PrintAll(ListCabor L)
{
	adrCabor P;
	adrNegara Q;
	
	if(IsEmpty(L))
		printf("List Kosong...");
	else
	{
		P=L.first;
		
		while(P!=NULL)
		{
			printf("=");
			printf("=");
			printf("=");
			printf("\n\nKode Cabor : %s",P->C.kodeCab);
			printf("\nNama Cabor : %s",P->C.namaCab);
			printf("\n==============================");				
			if(HaveNegara(P)==0)
			{
				printf("\nBelum ada Negara yang Berpartisipasi");
				printf("\n=======================================");
			}else
			{
				Q=P->firstNegara;
				PrintNegaradanAtlet(Q);
			}	
			P=P->nextCabor;
		}
	}
}

/////////////FUNGSI LIST (BIASA) PENAMPUNG
void CreateEmptyList(List *L)
{
	(*L).first=NULL;
}

int IsEmptyList(List L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;
}

address Alokasi(DataNegara C)
{
	address P;
	P=(address) malloc(sizeof(Node));
	P->N=C;
	P->Next=NULL;
	
	return P;
}

int cekNamaNegaraListTemp(List LT,string namaNeg)
{
	address temp;
	
	if(LT.first!=NULL)
	{
		temp=LT.first;
		while(temp!=NULL)
		{
			if(strcmpi(temp->N.namaNeg,namaNeg)==0)
			{
				return 1;
			}
			temp=temp->Next;
		}
	}	
	return 0;
}

void insertFirst(List *LT, DataNegara C)
{
	address P;
	P=Alokasi(C);
	P->Next=(*LT).first;
	(*LT).first=P;
}

void insertLast(List *LT, DataNegara C)
{
	address Last,T;
	
	if(IsEmptyList(*LT))
	{
		insertFirst(&(*LT),C);
	}else
	{
		T=Alokasi(C);
		Last=(*LT).first;
		while(Last->Next!=NULL)
		{
			Last=Last->Next;
		}
		Last->Next=T;
	}
}

void BubbleSort(List LT)
{
	address P,Q;
	DataNegara temp;
	
	P=LT.first;
	while(P!=NULL)
	{
		Q=P->Next;
		while(Q!=NULL)
		{
			if(P->N.emas < Q->N.emas)
			{
				temp=P->N;
				P->N=Q->N;
				Q->N=temp;	
			}
			if(P->N.emas==Q->N.emas)
			{
				if(P->N.perak < Q->N.perak)
				{
					temp=P->N;
					P->N=Q->N;
					Q->N=temp;	
				}
				if(P->N.perak==Q->N.perak)
				{
					if(P->N.perunggu < Q->N.perunggu)
					{
						temp=P->N;
						P->N=Q->N;
						Q->N=temp;
					}
				}
			}
			Q=Q->Next;
		}
		P=P->Next;
	}
	ShowRanking(LT);
	
}

void ShowRanking(List LT)
{
	address P;
	int i=0,total;
	
	P=LT.first;
	printf("\n---------------------------------------------------------------------------------------------------------");
	printf("\n| Rank\t| Nama Negara\t\t\t| Emas\t\t| Perak\t\t| Perunggu\t| Total Medali\t|");
	printf("\n---------------------------------------------------------------------------------------------------------");
	while(P!=NULL)
	{
		i++;
		total=0;
		total = P->N.emas+P->N.perak+P->N.perunggu;
		if(strlen(P->N.namaNeg)<6)
			printf("\n| %d\t| %s\t\t\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",i,P->N.namaNeg,P->N.emas,P->N.perak,P->N.perunggu,total);
		else if(strlen(P->N.namaNeg)<=13)
			printf("\n| %d\t| %s\t\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",i,P->N.namaNeg,P->N.emas,P->N.perak,P->N.perunggu,total);
		else if(strlen(P->N.namaNeg)<=23)
			printf("\n| %d\t| %s\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",i,P->N.namaNeg,P->N.emas,P->N.perak,P->N.perunggu,total);
		else
			printf("\n| %d\t| %s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",i,P->N.namaNeg,P->N.emas,P->N.perak,P->N.perunggu,total);
		P=P->Next;
	}
	printf("\n---------------------------------------------------------------------------------------------------------");
}

void HitungMendali(List LT, ListCabor L)
{
	address bantu;
	adrCabor temp=L.first;
	
	bantu=LT.first;
	
	while(temp!=NULL)
	{
		if(strcmpi(temp->C.juara1,"kosong")!=0)
		{
			bantu=LT.first;
			while(bantu!=NULL)
			{
				if(strcmpi(temp->C.juara1,bantu->N.kodeNeg)==0)
				{
					bantu->N.emas++;
				}
				if(strcmpi(temp->C.juara2,bantu->N.kodeNeg)==0)
				{
					bantu->N.perak++;
				}
				if(strcmpi(temp->C.juara3,bantu->N.kodeNeg)==0)
				{
					bantu->N.perunggu++;
				}
				bantu=bantu->Next;
			}
		}
		temp=temp->nextCabor;
	}
}

void initmedali(List *LT)
{
	address temp;
	
	temp=(*LT).first;
	
	while(temp!=NULL)
	{
		temp->N.emas=0;
		temp->N.perak=0;
		temp->N.perunggu=0;
		
		temp=temp->Next;
	}
}

int hapusnegaramedali(ListCabor L, string kodeNeg)
{
	int a=0;
	adrCabor bantu;
	adrNegara temp;
	
	bantu=L.first;
	
	while(bantu!=NULL)
	{
		temp=bantu->firstNegara;
		while(temp!=NULL)
		{
			if(strcmpi(temp->N.kodeNeg,kodeNeg)==0)
			{
				a++;
			}
			temp=temp->nextNegara;
		}
		bantu=bantu->nextCabor;
	}
	return a;
}

void DeleteFirstNegaraMedali(List *LT)
{
	address del;
	

		del = (*LT).first;
		(*LT).first=del->Next;
		free(del);
}

void hapusNegaraMedali(List *LT, string kodeNeg)
{
	address del, bantu;
	
	if(strcmpi((*LT).first->N.kodeNeg,kodeNeg)==0)
	{
		DeleteFirstNegaraMedali(&(*LT));
	}
	else
	{
		bantu=(*LT).first;
		while(bantu!=NULL && strcmpi(bantu->Next->N.kodeNeg,kodeNeg)!=0)
		{
			bantu=bantu->Next;
		}
		del=bantu->Next;
		bantu->Next = del->Next;
		free(del);
	}
	
}
