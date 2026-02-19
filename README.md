# TinyML Memory Efficient Tensor Project

Bu proje, bellek kısıtlı mikrodenetleyiciler için C dilinde geliştirilmiş dinamik bir tensör yapısıdır.

## Teknik Özellikler
- **Veri Yapısı:** `Union` kullanılarak Float32, Float16 ve Int8 tipleri aynı bellek alanında yönetilir.
- **Optimizasyon:** Quantization (Nicemleme) işlemi ile bellek kullanımı 4 byte'tan 1 byte'a düşürülür.
- **Hedef Cihazlar:** Arduino, ESP32 ve diğer RAM kısıtlı gömülü sistemler.

## Çalıştırma Talimatı
1. Derleme: `gcc main.c -o tensor`
2. Çalıştırma: `./tensor`

## Geliştirme Süreci
Bu proje, **Gemini 2.0 Flash** yapay zeka modeli ile **Agentic Kodlama** prensipleri çerçevesinde geliştirilmiştir.
