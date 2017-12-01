#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*M.Yaşar AFACAN tarafından yazılmıştır.
Yardım(Bu program için) öneri ve eleştirileriniz için "m.yasar.afacan@gmail.com" mail atabilirsiniz.*/
int main()
{
	int x, i = 0, j = 0,tur,sayi = 1,tekrar;
	printf("Matris degerini giriniz.");
	scanf_s("%d", &x); /* Visual studio community 2017 scanf kullanırken hata alıyordum scanf_s olarak aynı şekilde kullanınca
                      sorun çözüldü nedeninini bilmiyorum.Aynı sorunla karşılaşan olursa bu şekilde çözebilir.
                      Ne kadar dogrudur bilmiyorum tabi bu şekilde çözmek.*/
	int **a = (int *)malloc(sizeof(int)* x); // Pointer ile iki boyutlu bir dizi(array) oluşturarak martis sınırlamasını 
                                             ortadan kaldırıyoruz.
										            //Kullanıcı dilediği boyutta giriş yapabiliyor.
	for (int k = 0; k < x; k++)
	{
		a[k] = (int *)malloc(sizeof(int)*x);	// pointer kullanarak array oluşturma hakkında internetten bilgi bulabilirsiniz.
	}
	if (x % 2 == 0)
	{
		tekrar = x / 2; /* Çift rakamlarda aşağıdaki döngü martis boyutunun yarısı kadar dönmesi yeterli oluyor.
                       Aksi halde bir fazlası dönerse yeterli oluyor.
					             Bunun için bir if else yapısı kullandım. */
	}
	else
	{
		tekrar = (x / 2) + 1;
	}
	for (tur = 0; tur < tekrar; tur++) // Çözüm belirli döngülerin tekrarından oluşuyor.
                                        Her tekrarı sayarak alttaki döngülerde kullanıyoruz.
	{
		for (j = (0 + tur); j < (x - tur); j++)
		{
			a[i][j] = sayi;
			sayi++;
		}
		j--;//Döngüden çıkan değer istediğimizden bir fazla veya eksik oluyor
          ona göre döngü sonlarında tekrar istediğimiz değere çekiyoruz.
		for (i = (1 + tur); i < (x - tur); i++)
		{
			a[i][j] = sayi;
			sayi++;
		}
		i--;
		for (j = (x - 2 - tur); j >= (0 + tur); j--)
		{
			a[i][j] = sayi; // kodları takip ederek incelerseniz anlayacağınızı düşünüyorum.
			sayi++;			
		}
		j++;
		for (i = (x - 2 - tur); i >= (1 + tur); i--)
		{
			a[i][j] = sayi;
			sayi++;
		}
		i++;
	}
	for (i = 0; i < x; i++) // Elde edilen değerler ekrana bastırılıyor.
	{
		for (j = 0; j < x; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
	_getch();
	return 0;
	}
