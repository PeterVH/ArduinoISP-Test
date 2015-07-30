CC = sdcc
#CFLAGS = -V
MFLAGS = --model-small --debug
LFLAGS = --xram-loc 0x4000 --code-loc 0x0000

DATA_DIR=../data
PORT?=/dev/ttyACM0

all: blink.hex knight-rider.hex

%.rel: %.c
	$(CC) -c $(CFLAGS) $(MFLAGS) $<

blink.hex: blink.rel delay.rel
	$(CC) $(MFLAGS) $(LFLAGS) $^ -o $@

knight-rider.hex: knight-rider.rel delay.rel
	$(CC) $(MFLAGS) $(LFLAGS) $^ -o $@

clean:
	rm -f *~ \#* *.asm *.cdb *.rel *.hex *.ihx *.lst *.map \
		*.rst *.sym *.lnk *.lib *.bin *.adb *.mem *.omf *.lk

%.bin: %.hex
	hex2bin <$< >$@

flash-%: %.hex
	avrdude -C $(DATA_DIR)/avrdude-at89s52.conf -c stk500v1 -P $(PORT) -b 19200 -p at89s52 -U flash:w:$*.hex:i

