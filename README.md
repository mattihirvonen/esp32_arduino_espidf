# PlatformIO Project Using Arduino + Espidf Frameworks
Reason to convert PlatformIO Arduino project use also ESP-IDF framework is lack of DMA based ACD conversion routine in Arduino framework
- adc_continuous_read()
Espidf framework contain this missing feature

This is tiny test application to use both frameworks in same PlatformIO project

Ref:
- https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html

