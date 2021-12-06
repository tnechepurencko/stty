#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <fcntl.h>

int getFFDLY(int ffdly) {
    if (ffdly == FF0) return 0;
    else if (ffdly == FF1) return 1;
}

int getNLDLY(int nldly) {
    if (nldly == NL0) return 0;
    else if (nldly == NL1) return 1;
}

int getVTDLY(int vtdly) {
    if (vtdly == VT0) return 0;
    else if (vtdly == VT1) return 1;
}

int getBSDLY(int bsdly) {
    if (bsdly == BS0) return 0;
    else if (bsdly == BS1) return 1;
}

int getTABDLY(int tabdly) {
    if (tabdly == TAB0) return 0;
    else if (tabdly == TAB1) return 1;
    else if (tabdly == TAB2) return 2;
}

int getCSIZE(int csize) {
    if (csize == CS5) return 5;
    else if (csize == CS6) return 6;
    else if (csize == CS7) return 7;
    else if (csize == CS8) return 8;
}

int getCRDLY(int crdly) {
    if (crdly == CR0) return 0;
    else if (crdly == CR1) return 1;
    else if (crdly == CR2) return 2;
    else if (crdly == CR3) return 3;
}

int getSpeed(int B) {
    switch (B) {
        case 0:  return 0;
        case 1:  return 50;
        case 2:  return 75;
        case 3:  return 110;
        case 4:  return 134;
        case 5:  return 150;
        case 6:  return 200;
        case 7:  return 300;
        case 8:  return 600;
        case 9:  return 1200;
        case 10:  return 1800;
        case 11:  return 2400;
        case 12:  return 4800;
        case 13:  return 9600;
        case 14:  return 19200;
        case 15:  return 38400;
        case 16:  return 57600;
        case 17:  return 115200;
        default: return INT_MAX; // does not possible
    }
}

void configure(char *configs, char *str, struct termios *term) {
    if (strcmp(str, "brkint") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~BRKINT;
        } else {
            term->c_iflag |= BRKINT;
        }
    }

    if (strcmp(str, "icrnl") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~ICRNL;
        } else {
            term->c_iflag |= ICRNL;
        }
    }

    if (strcmp(str, "iutf8") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IUTF8;
        } else {
            term->c_iflag |= IUTF8;
        }
    }

    if (strcmp(str, "crtscts") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CRTSCTS;
        } else {
            term->c_cflag |= CRTSCTS;
        }
    }

    if (strcmp(str, "iuclc") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IUCLC;
        } else {
            term->c_iflag |= IUCLC;
        }
    }

    if (strcmp(str, "ignbrk") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IGNBRK;
        } else {
            term->c_iflag |= IGNBRK;
        }
    }

    if (strcmp(str, "parmrk") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~PARMRK;
        } else {
            term->c_iflag |= PARMRK;
        }
    }

    if (strcmp(str, "cmspar") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CMSPAR;
        } else {
            term->c_cflag |= CMSPAR;
        }
    }

    if (strcmp(str, "olcuc") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~OLCUC;
        } else {
            term->c_oflag |= OLCUC;
        }
    }

    if (strcmp(str, "clocal") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CLOCAL;
        } else {
            term->c_cflag |= CLOCAL;
        }
    }

    if (strcmp(str, "opost") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~OPOST;
        } else {
            term->c_oflag |= OPOST;
        }
    }

    if (strcmp(str, "ignpar") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IGNPAR;
        } else {
            term->c_iflag |= IGNPAR;
        }
    }

    if (strcmp(str, "ocrnl") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~OCRNL;
        } else {
            term->c_oflag |= OCRNL;
        }
    }

    if (strcmp(str, "cread") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CREAD;
        } else {
            term->c_cflag |= CREAD;
        }
    }

    if (strcmp(str, "extproc") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~EXTPROC;
        } else {
            term->c_lflag |= EXTPROC;
        }
    }

    if (strcmp(str, "cr2") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~CRDLY;
        } else {
            term->c_oflag &= ~CRDLY;
            term->c_oflag |= CR2;
        }
    }

    if (strcmp(str, "onlcr") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~ONLCR;
        } else {
            term->c_oflag |= ONLCR;
        }
    }

    if (strcmp(str, "cstopb") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CSTOPB;
        } else {
            term->c_cflag |= CSTOPB;
        }
    }

    if (strcmp(str, "onocr") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~ONOCR;
        } else {
            term->c_oflag |= ONOCR;
        }
    }

    if (strcmp(str, "inpck") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~INPCK;
        } else {
            term->c_iflag |= INPCK;
        }
    }

    if (strcmp(str, "vt1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~VTDLY;
        } else {
            term->c_oflag &= ~VTDLY;
            term->c_oflag |= VT1;
        }
    }

    if (strcmp(str, "cr1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~CRDLY;
        } else {
            term->c_oflag &= ~CRDLY;
            term->c_oflag |= CR1;
        }
    }

    if (strcmp(str, "cr0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~CRDLY;
        } else {
            term->c_oflag &= ~CRDLY;
            term->c_oflag |= CR0;
        }
    }

    if (strcmp(str, "istrip") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~ISTRIP;
        } else {
            term->c_iflag |= ISTRIP;
        }
    }

    if (strcmp(str, "inlcr") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~INLCR;
        } else {
            term->c_iflag |= INLCR;
        }
    }

    if (strcmp(str, "echonl") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHONL;
        } else {
            term->c_lflag |= ECHONL;
        }
    }

    if (strcmp(str, "ff1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~FFDLY;
        } else {
            term->c_oflag &= ~FFDLY;
            term->c_oflag |= FF1;
        }
    }

    if (strcmp(str, "cs8") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CSIZE;
        } else {
            term->c_cflag &= ~CSIZE;
            term->c_cflag |= CS8;
        }
    }

    if (strcmp(str, "cr3") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~CRDLY;
        } else {
            term->c_oflag &= ~CRDLY;
            term->c_oflag |= CR3;
        }
    }

    if (strcmp(str, "noflsh") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~NOFLSH;
        } else {
            term->c_lflag |= NOFLSH;
        }
    }

    if (strcmp(str, "igncr") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IGNCR;
        } else {
            term->c_iflag |= IGNCR;
        }
    }

    if (strcmp(str, "flusho") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~FLUSHO;
        } else {
            term->c_lflag |= FLUSHO;
        }
    }

    if (strcmp(str, "echok") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHOK;
        } else {
            term->c_lflag |= ECHOK;
        }
    }

    if (strcmp(str, "bs1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~BSDLY;
        } else {
            term->c_oflag &= ~BSDLY;
            term->c_oflag |= BS1;
        }
    }

    if (strcmp(str, "isig") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ISIG;
        } else {
            term->c_lflag |= ISIG;
        }
    }

    if (strcmp(str, "xcase") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~XCASE;
        } else {
            term->c_lflag |= XCASE;
        }
    }

    if (strcmp(str, "ixon") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IXON;
        } else {
            term->c_iflag |= IXON;
        }
    }

    if (strcmp(str, "parodd") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~PARODD;
        } else {
            term->c_cflag |= PARODD;
        }
    }

    if (strcmp(str, "cs5") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CSIZE;
        } else {
            term->c_cflag &= ~CSIZE;
            term->c_cflag |= CS5;
        }
    }

    if (strcmp(str, "ixoff") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IXOFF;
        } else {
            term->c_iflag |= IXOFF;
        }
    }

    if (strcmp(str, "ixany") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IXANY;
        } else {
            term->c_iflag |= IXANY;
        }
    }

    if (strcmp(str, "nl1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~NLDLY;
        } else {
            term->c_oflag &= ~NLDLY;
            term->c_oflag |= NL1;
        }
    }

    if (strcmp(str, "tab1") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~TABDLY;
        } else {
            term->c_oflag &= ~TABDLY;
            term->c_oflag |= TAB1;
        }
    }

    if (strcmp(str, "tab0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~TABDLY;
        } else {
            term->c_oflag &= ~TABDLY;
            term->c_oflag |= TAB0;
        }
    }

    if (strcmp(str, "bs0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~BSDLY;
        } else {
            term->c_oflag &= ~BSDLY;
            term->c_oflag |= BS0;
        }
    }

    if (strcmp(str, "tab2") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~TABDLY;
        } else {
            term->c_oflag &= ~TABDLY;
            term->c_oflag |= TAB2;
        }
    }

    if (strcmp(str, "echoke") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHOKE;
        } else {
            term->c_lflag |= ECHOKE;
        }
    }

    if (strcmp(str, "vt0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~VTDLY;
        } else {
            term->c_oflag &= ~VTDLY;
            term->c_oflag |= VT0;
        }
    }

    if (strcmp(str, "ff0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~FFDLY;
        } else {
            term->c_oflag &= ~FFDLY;
            term->c_oflag |= FF0;
        }
    }

    if (strcmp(str, "imaxbel") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_iflag &= ~IMAXBEL;
        } else {
            term->c_iflag |= IMAXBEL;
        }
    }

    if (strcmp(str, "nl0") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~NLDLY;
        } else {
            term->c_oflag &= ~NLDLY;
            term->c_oflag |= NL0;
        }
    }

    if (strcmp(str, "icanon") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ICANON;
        } else {
            term->c_lflag |= ICANON;
        }
    }

    if (strcmp(str, "parenb") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~PARENB;
        } else {
            term->c_cflag |= PARENB;
        }
    }

    if (strcmp(str, "cs6") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CSIZE;
        } else {
            term->c_cflag &= ~CSIZE;
            term->c_cflag |= CS6;
        }
    }

    if (strcmp(str, "ofdel") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~OFDEL;
        } else {
            term->c_oflag |= OFDEL;
        }
    }

    if (strcmp(str, "iexten") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~IEXTEN;
        } else {
            term->c_lflag |= IEXTEN;
        }
    }

    if (strcmp(str, "cs7") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~CSIZE;
        } else {
            term->c_cflag &= ~CSIZE;
            term->c_cflag |= CS7;
        }
    }

    if (strcmp(str, "echoctl") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHOCTL;
        } else {
            term->c_lflag |= ECHOCTL;
        }
    }

    if (strcmp(str, "tostop") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~TOSTOP;
        } else {
            term->c_lflag |= TOSTOP;
        }
    }

    if (strcmp(str, "hupcl") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_cflag &= ~HUPCL;
        } else {
            term->c_cflag |= HUPCL;
        }
    }

    if (strcmp(str, "echoprt") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHOPRT;
        } else {
            term->c_lflag |= ECHOPRT;
        }
    }

    if (strcmp(str, "echo") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHO;
        } else {
            term->c_lflag |= ECHO;
        }
    }

    if (strcmp(str, "echoe") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_lflag &= ~ECHOE;
        } else {
            term->c_lflag |= ECHOE;
        }
    }

    if (strcmp(str, "onlret") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~ONLRET;
        } else {
            term->c_oflag |= ONLRET;
        }
    }

    if (strcmp(str, "ofill") == 0) {
        if (strcmp(configs, "-") == 0) {
            term->c_oflag &= ~OFILL;
        } else {
            term->c_oflag |= OFILL;
        }
    }
}

char flagAndVal(int flag, int value) {
    if ((flag & value) == 0) return '-';
    else return ' ';
}

void currentSettings(struct termios term) {
    printf("CSIZE%d %cCREAD %cCLOCAL %cPARENB %cPARODD\n %cCMSPAR %cHUPCL %cCRTSCTS %cCSTOPB\n",
           flagAndVal(term.c_cflag, PARENB), getCSIZE(term.c_cflag & CSIZE), flagAndVal(term.c_cflag, CREAD),
           flagAndVal(term.c_cflag, CLOCAL), flagAndVal(term.c_cflag, PARODD), flagAndVal(term.c_cflag, CMSPAR),
           flagAndVal(term.c_cflag, HUPCL), flagAndVal(term.c_cflag, CRTSCTS), flagAndVal(term.c_cflag, CSTOPB));
}

void localSettings(struct termios term) {
    printf("%cECHO %cECHOE %cECHOK %cECHOCTL %cECHOPRT\n %cECHONL %cECHOKE %cICANON %cIEXTEN %cISIG\n %cXCASE %cTOSTOP "
           "%cEXTPROC %cFLUSHO %cNOFLSH\n", flagAndVal(term.c_lflag, ECHO), flagAndVal(term.c_lflag, ECHOE),
           flagAndVal(term.c_lflag, ECHOK), flagAndVal(term.c_lflag, ECHOCTL), flagAndVal(term.c_lflag, ECHOPRT),
           flagAndVal(term.c_lflag, ECHONL), flagAndVal(term.c_lflag, ECHOKE), flagAndVal(term.c_lflag, ICANON),
           flagAndVal(term.c_lflag, IEXTEN), flagAndVal(term.c_lflag, ISIG), flagAndVal(term.c_lflag, XCASE),
           flagAndVal(term.c_lflag, TOSTOP),
           flagAndVal(term.c_lflag, EXTPROC), flagAndVal(term.c_lflag, FLUSHO), flagAndVal(term.c_lflag, NOFLSH));
}

void inputSettings(struct termios term) {
    printf("%c%cIXON %cIXOFF %cIUTF8 IGNBRK %cIGNPAR\n %cIGNCR %cBRKINT %cPARMRK %cISTRIP %cINLCR\n %cICRNL %cIUCLC %cIXANY "
           "%cIMAXBEL %cINPCK\n", flagAndVal(term.c_iflag, IXON), flagAndVal(term.c_iflag, IXOFF), flagAndVal(term.c_iflag, IUTF8),
           flagAndVal(term.c_iflag, IGNBRK), flagAndVal(term.c_iflag, IGNPAR), flagAndVal(term.c_iflag, IGNCR),
           flagAndVal(term.c_iflag, BRKINT),
           flagAndVal(term.c_iflag, PARMRK), flagAndVal(term.c_iflag, ISTRIP), flagAndVal(term.c_iflag, INLCR),
           flagAndVal(term.c_iflag, ICRNL),
           flagAndVal(term.c_iflag, IUCLC), flagAndVal(term.c_iflag, IXANY), flagAndVal(term.c_iflag, IMAXBEL),
           flagAndVal(term.c_iflag, INPCK));
}

void outputSettings(struct termios term) {
    printf("NLDLY%d CRDLY%d TABDLY%d BSDLY%d VTDLY%d\n FFDLY%d %cONLRET %cONLCR %cONOCR %cOFILL\n "
           "%cOFDEL %cOPOST %cOLCUC %cOCRNL\n",
           getNLDLY(term.c_oflag & NLDLY), getCRDLY(term.c_oflag & CRDLY), getTABDLY(term.c_oflag & TABDLY),
           getBSDLY(term.c_oflag & BSDLY), getVTDLY(term.c_oflag & VTDLY), getFFDLY(term.c_oflag & FFDLY),
           flagAndVal(term.c_oflag, ONLRET), flagAndVal(term.c_oflag, ONLCR), flagAndVal(term.c_oflag, ONOCR),
           flagAndVal(term.c_oflag, OFILL), flagAndVal(term.c_oflag, OFDEL), flagAndVal(term.c_oflag, OPOST),
           flagAndVal(term.c_oflag, OLCUC), flagAndVal(term.c_oflag, OCRNL));
}

void humanReadable(int descriptor, struct winsize size) {
    struct termios term;
    if (tcgetattr(descriptor, &term) == 0) {
        printf("speed = %d; row = %d; column = %d; line = %d;\n", getSpeed(term.c_ispeed), size.ws_row, size.ws_col, term.c_line);
        printf("intr = ^C; quit = ^/; erase = ^?; kill = ^U; eof = ^D; eol = <undef>; eol2 = <undef>; swtch = <undef>; "
               "start = ^Q; stop = ^S; susp = ^Z; rprnt = ^R; werase = ^W; lnext = ^V; discard = ^O; min = 1; time = 0;\n");

        currentSettings(term);
        localSettings(term);
        inputSettings(term);
        outputSettings(term);

        return;
    }

    printf("Wrong File Descriptor!\n");
}

void sttyReadable(int descriptor) {
    struct termios term;

    if (tcgetattr(descriptor, &term) == 0) {
        printf("%x:", term.c_cflag);
        printf("%x:", term.c_lflag);
        printf("%x:", term.c_iflag);
        printf("%x:", term.c_oflag);

        for (int i = 0; i < NCCS - 1; i++) {
            printf("%x:", term.c_cc[i]);
        }

        printf("%x\n", term.c_cc[NCCS - 1]);
    }
}

int main(int argc, char **argv) {
    int flag = 0;

    char *device;

    char command1[1000];
    char command2[2];

    struct winsize size;
    struct termios term;

    int descriptor = STDOUT_FILENO;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    if (argc == 1) {
        if (tcgetattr(descriptor, &term) == 0) {
            printf("speed = %d; line = %d;\n", getSpeed(term.c_ispeed), term.c_line);
            printf("%cbrkint %cimaxbel %ciutf8\n", flagAndVal(term.c_iflag, BRKINT), flagAndVal(term.c_iflag, IMAXBEL),
                   flagAndVal(term.c_iflag, IUTF8));
        } else {
            printf("Wrong File Descriptor!\n");
            return -1;
        }
    } else if (argc == 2) {
        if (strcmp(argv[1], "-a") == 0) {
            humanReadable(descriptor, size);
        } else if (strcmp(argv[1], "-g") == 0) {
            sttyReadable(descriptor);
        } else {
            printf("Wrong Argument!");
            return -1;
        }
    } else if (argc >= 3) {
        if (strcmp(argv[1], "-F") == 0) {
            device = argv[2];
            descriptor = open(device, O_RDWR | O_NOCTTY | O_NONBLOCK);

            if (descriptor == -1) {
                printf("Cannot Open The Port!");
                return -1;
            } else if (strcmp(argv[3], "-a") == 0) {
                humanReadable(descriptor, size);
            } else if (strcmp(argv[3], "-g") == 0) {
                sttyReadable(descriptor);
            } else {
                if (tcgetattr(descriptor, &term) == 0) {
                    for (int i = 3; i < argc; i++) {
                        command2[0] = argv[i][0];
                        size_t len = strlen(argv[i]);

                        if (strcmp(command2, "-") == 0) {
                            memcpy(command1, &argv[i][1], len - 1);
                        } else {
                            memcpy(command1, &argv[i][0], len);
                        }
                        configure(command2, command1, &term);
                    }

                    tcsetattr(descriptor, TCSAFLUSH, &term);
                } else {
                    printf("Wrong File Descriptor!\n");
                    return -1;
                }
            }
        } else {
            if (tcgetattr(descriptor, &term) == 0) {
                for (int i = 1; i < argc; i++) {
                    command2[0] = argv[i][0];
                    size_t len = strlen(argv[i]);

                    if (strcmp(command2, "-") == 0) {
                        memcpy(command1, &argv[i][1], len - 1);
                    } else {
                        memcpy(command1, &argv[i][0], len);
                    }

                    configure(command2, command1, &term);
                }

                tcsetattr(descriptor, TCSAFLUSH, &term);
            } else {
                printf("Wrong File Descriptor!\n");
                return -1;
            }
        }
    }

    return 0;
}
