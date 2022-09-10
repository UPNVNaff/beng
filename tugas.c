#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
Andi memiliki akun bank dengan dengan saldo awal 500rb. Akun bank Andi dapat melakukan transfer dana, penarikan dana, dan deposit dana.
Simulasikan akun bank milik andi dengan menerapkan pointer dan fungsi.
*/

int i, pin, pilihan, deposit, total, tariktunai, rektujuan, nominaltf;
int saldo = 500000; 
int *ptr_saldo = &saldo;

void akun(){
    login:
    printf("Silahkan masukan kode pin anda : ");
    scanf("%d", &pin);
    if (pin == 123456){
        printf("Login SUKSES!\n");
    }
    else{
        printf("Login GAGAL!\n");
        goto login;
    }
}
void menu(){
    system("clear");
    printf("********************************\n");
    printf("              MENU              \n");
    printf("1. Transfer\n");
    printf("2. Penarikan Tunai\n");
    printf("3. Deposit Tunai\n");
    printf("4. Cek Saldo\n");
    printf("5. EXIT\n");
    printf("********************************\n");
}
void transfer(){
    system("clear");
    printf("Masukan nomor rekening tujuan : ");
    scanf("%d", &rektujuan);
    printf("Masukan nominal yang akan di transfer : ");
    scanf("%d", &nominaltf);
    saldo = saldo - nominaltf;
    system("clear");
    printf("\nTransfer ke no rekening %d sebesar %d Telah berhasil!", rektujuan, nominaltf);
}
void tarik(){
    system("clear");
    printf("Silahkan masukan jumlah yang ingin ditarik!\n");
    printf("1. 50.000\n");
    printf("2. 100.000\n");
    printf("3. 250.000\n");
    printf("4. 500.000\n");
    printf("5. Jumlah lain\n");
    printf("Masukan pilihan : ");
    scanf("%d", &pilihan);
    system("clear");
    if (pilihan == 1){
        saldo = saldo - 50000;
        printf("Tarik tunai sebesar 50.000\n");
        printf("Total : %d", saldo);
    }
    else if (pilihan == 2){
        saldo = saldo - 100000;
        printf("Tarik tunai sebesar 100.000\n");
        printf("Total : %d", saldo);
    }
    else if (pilihan == 3){
        saldo = saldo - 250000;
        printf("Tarik tunai sebesar 250.000\n");
        printf("Total : %d", saldo);
    }
    else if (pilihan == 4){
        saldo = saldo - 500000;
        printf("Tarik tunai sebesar 500.000\n");
        printf("Total : %d", saldo);
    }
    else if (pilihan == 5){
        printf("Masukan nominal yang akan ditarik : ");
        scanf("%d", &tariktunai);
        saldo = saldo - tariktunai;
        printf("Tarik tunai sebesar 500.000\n");
        printf("Total : %d", saldo);
    }
    else{
        printf("Tidak ada pilihan yang dipilih!");
    }
}
void depo(){
    system("clear");
    printf("\nSaldo anda : %d", *ptr_saldo);
    printf("\nMasukan nominal yang akan di deposit : ");
    scanf("%d", &deposit);
    saldo = saldo + deposit;
    system("clear");
    printf("\nJumlah deposit : %d", deposit);
    printf("\nTotal : %d", saldo);

}
void ceksaldo(){
    system("clear");
    printf("\nSaldo anda : %d", *ptr_saldo);
}
int main(){
    printf("Silahkan Login!\n");
    akun();
    balik:
    menu();
    printf("Silahkan pilih : ");
    scanf("%d", &pilihan);
    if (pilihan == 1){
        transfer();
    }
    else if (pilihan == 2){
        tarik();
    }
    else if (pilihan == 3){
        depo();
    }
    else if (pilihan == 4){
        saldo:
        ceksaldo();
        printf("\n\n1. Cek kembali\n");
        printf("2. Kembali ke MENU\n");
        printf("3. EXIT\n");
        printf("Silahkan pilih : ");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            goto saldo;
        }
        else if (pilihan == 2){
            goto balik;
        }
        else if (pilihan == 3){
            printf("\nTerima Kasih :)");
            return 0;
        }
        else{
            return 0;
        }
    }
    else if (pilihan == 5){
        return 0;
    }
    else{
        printf("Pilihan tidak ada!");
        goto balik;
    }
    printf("\n\nApakah ingin melajutkan transaksi : \n");
    printf("1. YA\n");
    printf("2. TIDAK\n");
    printf("Masukan pilihan : ");
    scanf("%d", &pilihan);
    if (pilihan == 1){
        goto balik;
    }
    else if (pilihan == 2){
        printf("\n\nTerima Kasih! :)");
        return 0;
    }
    else{
        return 0;
    }
}