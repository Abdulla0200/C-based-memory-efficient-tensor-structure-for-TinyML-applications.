#include <stdio.h>
#include <stdint.h>

/* 1. TENSOR TIPI TANIMLAMA (Enum)
   Bellek durumuna göre hangi veriyi kullandığımızı takip ederiz.
*/
typedef enum {
    TYPE_F32,    // 32-bit Float (Standart)
    TYPE_F16,    // 16-bit Float (Yarım hassasiyet)
    TYPE_INT8    // 8-bit Integer (Sıkıştırılmış/Quantized)
} DataType;

/* 2. DINAMIK VERI YAPISI (Union) - ÖDEVİN EN ÖNEMLİ KISMI
   Union sayesinde bu 3 farklı veri tipi aynı bellek adresini paylaşır.
   Bu, mikrodenetleyicilerde RAM tasarrufu sağlar.
*/
typedef union {
    float f32;      // 4 byte
    uint16_t f16;   // 2 byte
    int8_t i8;      // 1 byte
} TensorData;

/* 3. ANA TENSOR YAPISI (Struct)
*/
typedef struct {
    TensorData data;
    DataType type;
} Tensor;

/* 4. QUANTIZATION (NICEMLEME) FONKSIYONU
   Float veriyi 8-bitlik alana sıkıştırarak bellek kullanımını %75 azaltır.
*/
int8_t quantize(float input, float scale) {
    printf("[İŞLEM] %.2f değeri %.2f katsayısı ile sıkıştırılıyor...\n", input, scale);
    return (int8_t)(input / scale);
}

int main() {
    Tensor myTensor;
    float realValue = 25.5f;
    float scale = 0.5f; 

    printf("--- TinyML Tensor Yonetim Demosu ---\n\n");

    // ADIM A: Standart Float32 Kullanımı
    myTensor.type = TYPE_F32;
    myTensor.data.f32 = realValue;
    printf("1. Mod: Float32\n   Deger: %.2f | Bellek: %zu bytes\n\n", 
            myTensor.data.f32, sizeof(myTensor.data));

    // ADIM B: Quantization (Int8) Kullanımı - RAM Tasarrufu
    myTensor.type = TYPE_INT8;
    myTensor.data.i8 = quantize(realValue, scale);
    
    printf("2. Mod: Int8 (Quantized)\n   Deger: %d | Bellek: %zu byte\n", 
            myTensor.data.i8, sizeof(myTensor.data.i8));

    printf("\n[BAŞARI] Ayni bellek alani kullanilarak RAM optimize edildi.\n");

    return 0;
}