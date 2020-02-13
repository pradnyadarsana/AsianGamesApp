#include "header.h"

void main() 
{
	ListCabor L;
	List LT;
	
	adrCabor P;
	adrNegara Q;
	adrAtlet R;

	DataCabor C;
	DataNegara N;
	DataAtlet A;
	
	char menu,menuCab;
	string kodeAlt,nama,kelamin;
	int usia;
	string kodeNeg,namaNeg;
	string kodeCab,namaCab;
	string tempjuara1,tempjuara2,tempjuara3;
	int emas, perak, perunggu;	
	
	CreateEmpty(&L);
	CreateEmptyList(&LT);
	
	do{
		system("cls");
		printf("----------- ASIAN GAMES -----------\n");
		printf("|                                 |\n");
		printf("|   [1]. Kelola Cabang Olahraga   |\n");
		printf("|   [2]. Kelola Negara            |\n");
		printf("|   [3]. Kelola Atlet             |\n");
		printf("|   [4]. Perlombaan               |\n");
		printf("|   [5]. Report                   |\n");
		printf("|                                 |\n");
		printf("|      Tekan ESC untuk keluar     |\n");
		printf("|                                 |\n");
		printf("-------- Pilih salah satu ---------\n");
		menu=getch();
		switch(menu)
		{
			case '1': 
						do
						{
							system("cls");
							printf("   [KELOLA CABANG NEGARA]\n");
							printf("\n[1]. Input Cabang Olahraga");
							printf("\n[2]. Hapus Cabang Olahraga");
							printf("\n[3]. Edit Cabang Olahraga");
							printf("\n[4]. Tampil Cabang Olahraga");
							printf("\n[ESC] Exit\n");
							menuCab=getch();
							switch(menuCab)
							{
								case '1': 
										do
										{	
											printf("\n\nKode Cabang Olahraga	: ");fflush(stdin);gets(kodeCab);
											if(strlen(kodeCab)<=0)
											{
												printf("\n\t[!] Kode Cabang Olahraga TIDAK boleh Kosong [!]");
											}else
											if(cekUnikKodeCabor(L,kodeCab)==0)
											{
												printf("\n\t[!] Kode Cabang Olahraga [%s] SUDAH ada [!]",kodeCab);
											}
										}while(cekUnikKodeCabor(L,kodeCab)==0 || strlen(kodeCab)<=0);
										do
										{
											printf("\nNama Cabang Olahraga	: ");fflush(stdin);gets(namaCab);
											if(strlen(namaCab)<=0)
											{
												printf("\n\t[!] Nama Cabang Olahraga TIDAK boleh Kosong [!]");
											}else
											if(cekUnikNamaCabor(L,namaCab)==0)
											{
												printf("\n\t[!] Nama Cabang Olahraga [%s] SUDAH ada [!]",namaCab);
											}
										}while(cekUnikNamaCabor(L,namaCab)==0 || strlen(namaCab)<=0);
										
										C=MakeDataCabor(kodeCab,namaCab);
										insertLastCabor(&L,C);
										getch();
										break;
								
								case '2':
										printf("\n\nKode Cabang Olahraga yang ingin di Hapus	: ");fflush(stdin);gets(kodeCab);
										deleteAtCabor(&L,kodeCab);
										getch();
										break;
								
								case '3':
										printf("\n\nKode Cabang Olahraga yang ingin di Edit : ");fflush(stdin);gets(kodeCab);
										P=FindCabor(L,kodeCab);
										if(P!=NULL)
										{
											do
											{	
												printf("\nKode Cabang Olahraga	: ");fflush(stdin);gets(kodeCab);
											}while(cekUnikKodeCabor(L,kodeCab)==0);
											do
											{
												printf("\nNama Cabang Olahraga	: ");fflush(stdin);gets(namaCab);
											}while(cekUnikNamaCabor(L,namaCab)==0);	
											EditDataCabor(P,kodeCab,namaCab);
										}else
										{
											printf("\n\n\tData Cabang Olahraga Tidak ditemukan");
										}
										getch();
										break;
										
								case '4':
										printCabor(L);
										getch();
										break;
								
								case 27: break;
							}
						}while(menuCab!=27);
					break;
					getch();
					
			case '2':	if(IsEmpty(L)==0)
						{
							do
							{
								system("cls");
								printf("  [KELOLA NEGARA]\n");
								printf("\n[1].  Input Negara");
								printf("\n[2].  Hapus Negara");
								printf("\n[3].  Edit Negara");
								printf("\n[4].  Tampil Cabang Olahraga dan Negara");
								printf("\n[ESC] Exit\n");
								menuCab=getch();
								switch(menuCab)
								{
									case '1':	printf("\n\nKode Cabang Olahraga yang di Tambahkan Negara	: ");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													do
													{	
														printf("\nNama Negara	: ");fflush(stdin);gets(namaNeg);
														if(strlen(namaNeg)<=0)
														{
															printf("\n\t[!] Nama Negara TIDAK boleh Kosong [!]");
														}else
														if(cekUnikNamaNegara(P,namaNeg)==0)
														{
															printf("\n\t[!] Negara [%s] SUDAH Terdafar pada Cabang Olahraga [%s] [!]",namaNeg,kodeCab);
														}
														else
														if(strlen(namaNeg)>25)
														{
															printf("\n\t[!] Nama Negara TIDAK boleh lebih dari 25 karakter [!]");
														}
													}while(cekUnikNamaNegara(P,namaNeg)==0 || strlen(namaNeg)<=0 || strlen(namaNeg)>25);
													if(cekNamaNegara(L,P,namaNeg)==0)
													{
														copyKodeNegara(L,P,namaNeg,kodeNeg);
													}else
													{
														do
														{
															printf("\nKode Negara	: ");fflush(stdin);gets(kodeNeg);
															if(strlen(kodeNeg)<=0)
															{
																printf("\n\t[!] Kode Negara TIDAK boleh Kosong [!]");
															}else
															if(cekUnikNamaNegara(P,namaNeg)==0)
															{
																printf("\n\t[!] Kode Negara [%s] SUDAH Terdafar pada Cabang Olahraga [%s] [!]",kodeNeg,kodeCab);
															}
														}while(cekUnikKodeNegara(P,kodeNeg)==0 || strlen(namaNeg)<=0);
													}
													N = MakeDataNegara(kodeNeg,namaNeg);
													insertLastNegara(P,N);
													if(cekNamaNegaraListTemp(LT,namaNeg)!=1)
													{
														insertLast(&LT,N);
													}
												}else
													printf("\n\tCabor tidak ditemukan");
												getch();
												break;
									
									case '2':	printf("\n\nKode Cabang Olahraga yang ingin di hapus salah satu Negaranya	: ");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													printf("\nKode Negara yang ingin di hapus	: ");fflush(stdin);gets(kodeNeg);
													DeleteAtNegara(L, &LT, P, kodeNeg);
												}else
													printf("Cabor tidak ditemukan");	
												getch();
												break;
									
									case '3':	printf("\n\nKode Cabang Olahraga yang ingin di Edit salah satu Negaranya	: ");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													printf("\nKode Negara yang ingin di Edit	: ");fflush(stdin);gets(kodeNeg);
													Q = FindNegara(P,kodeNeg);
													if(Q!=NULL)
													{
														do
														{	
															printf("\nNama Negara	: ");fflush(stdin);gets(namaNeg);
															if(strlen(namaNeg)<=0)
															{
																printf("\n\t[!] Nama Negara TIDAK boleh Kosong [!]");
															}else
															if(cekUnikNamaNegara(P,namaNeg)==0)
															{
																printf("\n\t[!] Negara [%s] SUDAH Terdafar pada Cabang Olahraga [%s] [!]",namaNeg,kodeCab);
															}
															if(strlen(namaNeg)>25)
															{
																printf("\n\t[!] Nama Negara TIDAK boleh lebih dari 25 karakter [!]");
															}
														}while(cekUnikNamaNegara(P,namaNeg)==0 || strlen(namaNeg)<=0 || strlen(namaNeg)>25);
														if(cekNamaNegara(L,P,namaNeg)==0)
														{
															copyKodeNegara(L,P,namaNeg,kodeNeg);
														}else
														{
															do
															{
																printf("\nKode Negara	: ");fflush(stdin);gets(kodeNeg);
																if(strlen(kodeNeg)<=0)
																{
																	printf("\n\t[!] Kode Negara TIDAK boleh Kosong [!]");
																}else
																if(cekUnikNamaNegara(P,namaNeg)==0)
																{
																	printf("\n\t[!] Kode Negara [%s] SUDAH Terdafar pada Cabang Olahraga [%s] [!]",kodeNeg,kodeCab);
																}
															}while(cekUnikKodeNegara(P,kodeNeg)==0 || strlen(namaNeg)<=0);
														}
														EditNegara(Q,namaNeg,kodeNeg);
													}else
														printf("\n\tNegara Tidak ditemukan");
												}else
													printf("\n\tCabor tidak ditemukan");	
												getch();
												break;
									
									case '4':	PrintCabordanNegara(L);
												getch();
												break;
											
									case 27: 	break;
								}
							}while(menuCab!=27);
						}else
						{
							printf("\n\n\tData CABOR masih KOSONG!");
							getch();
						}
						break;
						getch();
					
			case '3':	if(IsEmpty(L)==0)
						{
							do
							{
								system("cls");
								printf("  [KELOLA ATLET]\n");
								printf("\n[1].  Input Atlet");
								printf("\n[2].  Hapus Atlet");
								printf("\n[3].  Edit Atlet");
								printf("\n[4].  Tampil Cabang Olahraga,Negara dan Atlet");
								printf("\n[ESC] Exit\n");
								menuCab=getch();
								switch(menuCab)
								{
									case '1': 	printf("\n\nKode Cabang Olahraga yang di Tambahkan Atlet	:");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													printf("\nKode Negara yang ingin ditambahkan atlet	:");fflush(stdin);gets(kodeNeg);
													Q = FindNegara(P,kodeNeg);
													if(Q!=NULL)
													{
														do
														{	
															printf("\nKode Atlet	:");fflush(stdin);gets(kodeAlt);
															if(strlen(kodeAlt)<=0)
															{
																printf("\n\t[!] Kode Atlet TIDAK boleh Kosong [!]");
															}else
															if(cekUnikKodeAtlet(Q,kodeAlt)==0)
															{
																printf("\n\t[!] Kode Atlet [%s]Sudah Ada [!]",kodeAlt);
															}
														}while(cekUnikKodeAtlet(Q,kodeAlt)==0 || strlen(kodeAlt)<=0);
														do
														{
														printf("\nNama Atlet	:");fflush(stdin);gets(nama);
														if(strlen(nama)<=0)
														{
															printf("\n\t[!] Nama Atlet TIDAK boleh kosong [!]");
														}
														}while(strlen(nama)<=0);
														do
														{
														printf("\nJenis Kelamin Atlet [Pria / Wanita]	:");fflush(stdin);gets(kelamin);
														if(strlen(kelamin)<=0)
														{
															printf("\n\t[!] Jenis Kelamin TIDAK Boleh Kosong [!]");
														}else
														if(strcmpi(kelamin,"Pria")!=0 && strcmpi(kelamin,"wanita")!=0)
														{
															printf("\n\t[!] Jenis Kelamin Hanya Pria Dan Wanita [!]");
														}
														}while(strlen(kelamin)<=0 || strcmpi(kelamin,"Pria")!=0 && strcmpi(kelamin,"wanita")!=0);
														do
														{
														printf("\nUsia Atlet [Tahun]	:");scanf("%d",&usia);
														if(usia<15)
														{
															printf("\n\t[!] Usia Minimal Atlet 15 Tahun [!]");
														}
														}while(usia<15);
														A=MakeDataAtlet(kodeAlt,nama,kelamin,usia);
														insertLastAtlet(Q,A);
													}else
														printf("Negara Tidak di temukan");
												}else
													printf("Cabor tidak di temukan");
												getch();
												break;
									
									case '2':	printf("\n\nKode Cabang Olahraga yang ingin di hapus salah satu Atletnya	:");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													printf("\nKode Negara yang ingin di hapus Atletnya	:");fflush(stdin);gets(kodeNeg);
													Q = FindNegara(P,kodeNeg);
													if(Q!=NULL)
													{
														printf("Kode Atlet yang Ingin Di hapus	:");fflush(stdin);gets(kodeAlt);
														DeleteAtAtlet(Q,kodeAlt);
													}else
														printf("Negara Tidak di temukan");	
												}else
													printf("Cabor tidak ditemukan");	
												getch();
												break;
									
									case '3':	printf("\n\nKode Cabang Olahraga yang ingin di Edit salah satu Atletnya	:");fflush(stdin);gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													printf("\nKode Negara yang ingin di Edit Atletnya	:");fflush(stdin);gets(kodeNeg);
													Q = FindNegara(P,kodeNeg);
													if(Q!=NULL)
													{
														printf("Kode Atlet yang Ingin Di Edit	:");fflush(stdin);gets(kodeAlt);
														R=FindAtlet(Q,kodeAlt);
														if(R!=NULL)
														{
															do
														{
														printf("\nNama Atlet	:");fflush(stdin);gets(nama);
														if(strlen(nama)<=0)
														{
															printf("\n\t[!] Nama Atlet TIDAK boleh kosong [!]");
														}
														}while(strlen(nama)<=0);
														do
														{
														printf("\nJenis Kelamin Atlet [Pria / Wanita]	:");fflush(stdin);gets(kelamin);
														if(strlen(kelamin)<=0)
														{
															printf("\n\t[!] Jenis Kelamin TIDAK Boleh Kosong [!]");
														}else
														if(strcmpi(kelamin,"Pria")!=0 && strcmpi(kelamin,"wanita")!=0)
														{
															printf("\n\t[!] Jenis Kelamin Hanya Pria Dan Wanita [!]");
														}
														}while(strlen(kelamin)<=0 || strcmpi(kelamin,"Pria")!=0 && strcmpi(kelamin,"wanita")!=0);
														do
														{
														printf("\nUsia Atlet [Tahun]	:");scanf("%d",&usia);
														if(usia<15)
														{
															printf("\n\t[!] Usia Minimal Atlet 15 Tahun [!]");
														}
														}while(usia<15);
															EditAtlet(R,kodeAlt,nama,kelamin,usia);
														}
													}else
														printf("Negara Tidak ditemukan");
												}else
													printf("Cabor tidak ditemukan");	
												getch();
												break;
									
									case '4':	PrintNegaraAtletbyCabor(L);
												getch();
												break;
											
									case 27: 	break;
								}
							}while(menuCab!=27);
						}else
						{
							printf("\n\n\tData CABOR masih KOSONG!");
							getch();
						}
						break;
						getch();
			
			case '4':	if(IsEmpty(L)==0)
						{
							do
							{
								system("cls");
								printf("\n====MENU PERLOMBAAN====");
								printf("\n[1]   Input Juara");
								printf("\n[2]   Update Juara");
								printf("\n[3]   Tampil Juara");
								printf("\n[ESC] EXIT\n");
								menuCab=getch();
								switch(menuCab)
								{
									case '1' :	printf("\n\nMasukan Kode Cabang OlahRaga : "); fflush(stdin); gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													if(strcmpi(P->C.juara1,"kosong")==0)
													{
														do
														{
														printf("\nMasukan Kode Negara yang mendapat EMAS pada cabor ini : "); fflush(stdin); gets(kodeNeg);
														Q = FindNegara(P,kodeNeg);
														if(Q!=NULL)
														{
															strcpy(P->C.juara1,kodeNeg);
															
															strcpy(tempjuara1,kodeNeg);
															printf("Emas Berhasil Ditambah !");
														}
														else
														{
															printf("\nKode Negara tidak ditemukan !!");
															getch();
														}
														}while(Q==NULL);
														do
														{
														printf("\nMasukan Kode Negara yang mendapat PERAK pada cabor ini : "); fflush(stdin); gets(kodeNeg);
														Q = FindNegara(P,kodeNeg);
														if(Q!=NULL)
														{
															strcpy(P->C.juara2,kodeNeg);
															strcpy(tempjuara2,kodeNeg);
															printf("Perak Berhasil Ditambah !");
														}
														else
														{
															printf("\nKode Negara tidak ditemukan !!");
															getch();
														}
														}while(Q==NULL);
														do
														{
														printf("\nMasukan Kode Negara yang mendapat PERUNGGU pada cabor ini : "); fflush(stdin); gets(kodeNeg);
														Q = FindNegara(P,kodeNeg);
														if(Q!=NULL)
														{
															strcpy(P->C.juara3,kodeNeg);
															strcpy(tempjuara3,kodeNeg);
															printf("Perunggu Berhasil Ditambah !");
														}
														else
														{
															printf("\nKode Negara tidak ditemukan !!");
															getch();
														}
														}while(Q==NULL);
													}else
														printf("\nJuara Pada Cabor ini terlah Terisi");
												}else
														printf("\nKode CabOr Tidak ditemukan !");
												getch();
												break;
												
									case '2' :	printf("\n\nMasukan Kode Cabang OlahRaga : "); fflush(stdin); gets(kodeCab);
												P = FindCabor(L,kodeCab);
												if(P!=NULL)
												{
													if(strcmpi(P->C.juara1,"kosong")!=0)
													{
														do
														{
															printf("\nMasukan Kode Negara yang mendapat EMAS pada cabor ini : "); fflush(stdin); gets(kodeNeg);
															Q = FindNegara(P,kodeNeg);
															if(Q!=NULL)
															{
																strcpy(P->C.juara1,kodeNeg);
																printf("Emas Berhasil Diedit !");
															}
															else
															{
																printf("\nKode Negara tidak ditemukan !!");
																getch();
															}
														}while(Q==NULL);
														do
														{
															printf("\nMasukan Kode Negara yang mendapat PERAK pada cabor ini : "); fflush(stdin); gets(kodeNeg);
															Q = FindNegara(P,kodeNeg);
															if(Q!=NULL)
															{
																strcpy(P->C.juara2,kodeNeg);
															}
															else
															{
																printf("\nKode Negara tidak ditemukan !!");
																getch();
															}
														}while(Q==NULL);
														do
														{
															printf("\nMasukan Kode Negara yang mendapat PERUNGGU pada cabor ini : "); fflush(stdin); gets(kodeNeg);
															Q = FindNegara(P,kodeNeg);
															if(Q!=NULL)
															{
																strcpy(P->C.juara3,kodeNeg);
															}
															else
															{
																printf("\nKode Negara tidak ditemukan !!");
																getch();
															}
														}while(Q==NULL);
													}
													}else
													{
														printf("\nKode CabOr Tidak ditemukan !");
														getch();	
													}
													break;
									
									case '3' :		printf("\n\nMasukan Kode Cabor : ");fflush(stdin);gets(kodeCab);
													P=FindCabor(L, kodeCab);
													if(P!=NULL)
													{
														printf("\nNama Cabor : %s", P->C.namaCab);
														Q=FindNegara(P, P->C.juara1);
														if(Q!=NULL)
														{
															printf("\n\n========================");
															printf("\nJuara 1");
															printf("\nKode Negara : %s",Q->N.kodeNeg);
															printf("\nNama Negara : %s",Q->N.namaNeg);
															printf("\n========================");
														}
														
														Q=FindNegara(P, P->C.juara2);
														if(Q!=NULL)
														{
															printf("\nJuara 2");
															printf("\nKode Negara : %s",Q->N.kodeNeg);
															printf("\nNama Negara : %s",Q->N.namaNeg);
															printf("\n========================");
														}
														Q=FindNegara(P, P->C.juara3);
														if(Q!=NULL)
														{
															printf("\nJuara 3");
															printf("\nKode Negara : %s",Q->N.kodeNeg);
															printf("\nNama Negara : %s",Q->N.namaNeg);
															printf("\n========================");
														}
													}
													getch();
													break;
									
									case 27 :	break;
								}
							}while(menuCab != 27);
						}
						else
						{
							printf("\n\n\tData CABOR masih KOSONG!");
							getch();
						}
						break;
			
			case '5':	if(IsEmpty(L)==0)
						{
							do{
								system("cls");
								printf("\n====MENU REPORT===");
								printf("\n[1]. Tampil Semua Data Cabang Olahraga, Negara, dan Atlet");
								printf("\n[2]. Daftar Atlet dari Negara tertentu");
								printf("\n[3]. Daftar Semua Cabor yang diikuti Negara tertentu");
								printf("\n[4]. Tabel Perolehan Medali");
								printf("\n[ESC] Exit\n");
								menuCab=getch();
								switch(menuCab)
								{
									case '1':	PrintAll(L);
												getch();
												break;
									
									case '2': 	printf("Masukan Kode Negara : ");fflush(stdin);gets(kodeNeg);
												PrintAllAtletbyNegara(L, kodeNeg);
												getch();
												break;
									
									case '3':	printf("Masukan Kode Negara : ");fflush(stdin);gets(kodeNeg);
												PrintCaborbyNegara(L, kodeNeg);
												getch();
												break;
												
									case '4':	HitungMendali(LT,L);
												BubbleSort(LT);	
												initmedali(&LT);
												getch();
												break;
								}
							}while(menuCab!=27);
						}else
						{
							printf("\n\n\tData CABOR masih KOSONG!");
							getch();
						}
						break;
			
			default:	printf("Inputan tak terdaftar\n");
						printf("\nTekan ENTER untuk melanjutkan\n");
						getch();
						break;
						
			case 27:	printf("Terima Kasih");
						getch();
						break;
		}
	
	}while(menu!=27);
}
