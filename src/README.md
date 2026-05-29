# Panduan Integrasi Mock Backend Serial (Pengembangan Paralel)

Dokumen ini berisi panduan bagi tim **User Interface (UI)** dan **Application Logic** untuk mulai mengembangkan dan menguji antarmuka program Sistem Inventarisasi Laboratorium tanpa harus menunggu implementasi perangkat keras (Arduino) dan komunikasi port Serial OS selesai dibangun.

## 📌 Konsep Dasar (Mocking)

Akan digunakan teknik *Stubbing/Mocking*. Kita **TIDAK** perlu memikirkan bagaimana cara komputer membuka port COM atau membaca kabel USB. 

Selama fase pengembangan ini, kita akan menggunakan file `mock_serial.c`. File ini mengimplementasikan fungsi-fungsi dari `serial_comm.h`, tetapi alih-alih mengirim data ke Arduino sungguhan, fungsi ini hanya akan mencetak apa yang "seharusnya" dikirim ke layar terminal, dan memberikan balasan palsu (seperti `"ACK_ADD"`) agar program C kita tidak *error* atau *freeze*.

---

## 📂 Struktur File yang Digunakan

Pastikan direktori kerjamu memiliki file-file berikut:
- `serial_comm.h` *(API Contract - JANGAN UBAH FILE INI)*
- `mock_serial.c` *(Backend palsu untuk testing)*
- `user_interface.h` & `user_interface.c` *(Pekerjaan Tim UI)*
- `app_logic.h` & `app_logic.c` *(Pekerjaan Tim Logic)*
- `main.c` *(Entry point program)*

---

## 🛠️ Cara Menggunakan API di dalam `app_logic.c`

File `app_logic.c` adalah otak dari aplikasi PC ini. File ini bertugas mengambil *input* bersih dari UI, menyusunnya menjadi format *string* CSV (`ADD,15,ESP32,...`), dan mengirimkannya ke Serial.

Berikut adalah contoh implementasi langsung pada fungsi `addInventory()` menggunakan API Mock Serial kita:

```c
// File: app_logic.c
#include <stdio.h>
#include "app_logic.h"
#include "user_interface.h" // Untuk memanggil promptInt dan promptString
#include "serial_comm.h"    // Untuk memanggil sendSerialData dan receiveSerialData

void addInventory() {
    int id, cat, loc, qTer, qDip, qRus;
    char name[9]; // 8 karakter + 1 null terminator
    char pic[4];  // 3 karakter + 1 null terminator
    
    char sendBuffer[128];
    char receiveBuffer[64];

    printf("\n--- TAMBAH DATA INVENTARIS ---\n");
    
    // 1. Ambil data dengan aman menggunakan modul UI
    promptInt("Masukkan ID Barang (0-126)   : ", &id);
    promptString("Masukkan Nama Barang (Max 8) : ", name, 9);
    promptInt("Kategori (0-3)               : ", &cat);
    promptInt("Lokasi Rak (0-63)            : ", &loc);
    promptInt("Jumlah Tersedia              : ", &qTer);
    promptInt("Jumlah Dipinjam              : ", &qDip);
    promptInt("Jumlah Rusak                 : ", &qRus);
    promptString("Inisial PIC (Max 3)          : ", pic, 4);

    // 2. Format data menjadi string sesuai protokol 96-bit Arduino
    sprintf(sendBuffer, "ADD,%d,%s,%d,%d,%d,%d,%d,%s\n", 
            id, name, cat, loc, qTer, qDip, qRus, pic);

    // 3. Kirim data ke "Arduino" (Saat ini akan ditangkap oleh mock_serial.c)
    sendSerialData(sendBuffer);

    // 4. Tunggu dan terima balasan dari "Arduino"
    receiveSerialData(receiveBuffer);

    // 5. Tampilkan status keberhasilan ke layar PC
    if (strncmp(receiveBuffer, "ACK_ADD", 7) == 0) {
        printf(">> [BERHASIL] Data berhasil disimpan ke memori sistem!\n");
    } else {
        printf(">> [GAGAL] Terjadi kesalahan komunikasi: %s\n", receiveBuffer);
    }
}