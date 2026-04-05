#include <switch.h>
#include <stdio.h>
#include <vector>

// R2-D2 Bluetooth Commands
void sendR2Command(uint8_t did, uint8_t cid, std::vector<uint8_t> data) {
    // This is where the app talks to Mission Control
    // In a full build, you'd use btdrvBleClientWriteGattAttribute here
    printf("Sending to R2-D2: DID 0x%02X, CID 0x%02X\n", did, cid);
}

int main(int argc, char **argv) {
    consoleInit(NULL);
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    PadState pad;
    padInitializeDefault(&pad);

    printf("\x1b[1;1H=== SWITCH R2-D2 CONTROLLER ===");
    printf("\x1b[3;1H[A] - Happy Beep");
    printf("\x1b[4;1H[B] - Spin Dome");
    printf("\x1b[5;1H[X] - Tripod Mode");
    printf("\x1b[6;1H[Y] - Bipod Mode");
    printf("\x1b[8;1HPress PLUS to Exit");

    while (appletMainLoop()) {
        padUpdate(&pad);
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_A) sendR2Command(0x17, 0x05, {0x01});
        if (kDown & HidNpadButton_B) sendR2Command(0x17, 0x05, {0x02});
        if (kDown & HidNpadButton_X) sendR2Command(0x16, 0x07, {0x01});
        if (kDown & HidNpadButton_Y) sendR2Command(0x16, 0x07, {0x00});

        if (kDown & HidNpadButton_Plus) break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;}

