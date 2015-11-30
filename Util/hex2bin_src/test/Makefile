test:
# Generates a checksum error, but 'make' will ignore this error ('-' before hex2bin)
	-hex2bin -c nochecksum.hex
	@cmp nochecksum.bin ref/nochecksum.ref & echo "Pass"
	hex2bin -c linear.hex
	@cmp linear.bin ref/linear.ref & echo "Pass"
	hex2bin -c segmented.hex
	@cmp segmented.bin ref/segmented.ref & echo "Pass"
	hex2bin -c example.hex
	@cmp example.bin ref/example.ref & echo "Pass"
	hex2bin -c -s 0 -p 0 example.hex
	@cmp example.bin ref/example2.ref & echo "Pass"
	mot2bin -c -s 0 -p 0 example2.s19
	@cmp example2.bin ref/example2.ref & echo "Pass"
	hex2bin -c test-end-memory.hex
	@cmp test-end-memory.bin ref/end-memory.ref & echo "Pass"
	hex2bin -c test-overlap.hex
	@cmp test-overlap.bin ref/overlap.ref & echo "Pass"
	hex2bin -c test.hex
	@cmp test.bin ref/test.ref & echo "Pass"
	hex2bin -c test-extra-lf.hex
	@cmp test-extra-lf.bin ref/extra-lf.ref & echo "Pass"

addr_mask:
	mot2bin -c test-addr_mask.s19
	@cmp test-addr_mask.bin ref/addr_mask.ref & echo "Pass"

pad:
	hex2bin -c -p 3A example.hex
	@cmp example.bin ref/pattern1.ref & echo "Pass"
	hex2bin -c -l 1000 example.hex
	@cmp example.bin ref/pattern2.ref & echo "Pass"
	hex2bin -c -p 3A -l 1000 example.hex
	@cmp example.bin ref/pattern3.ref & echo "Pass"
	hex2bin -c -p 3A -l 2000 example.hex
	@cmp example.bin ref/pattern4.ref & echo "Pass"

options:
	# for use in scripts
	-hex2bin < nul xx

	# usage
	-hex2bin -c
	-hex2bin -h
	-hex2bin -?
	-hex2bin -h example.hex
	-hex2bin -? example.hex
	-hex2bin -ecmd example.hex
	-hex2bin -e.cmd example.hex
	hex2bin -p 3A -l800000 example.hex

	# output to example.cmd
	hex2bin -e cmd example.hex
	hex2bin -e .cmd example.hex

pattern:
	-hex2bin -c -p 3A test.hex
	@cmp test.bin ref/pattern.ref & echo "Pass"

byte_swap:
	hex2bin -w test-byte-swap.hex
	@cmp test-byte-swap.bin ref/byte-swap.ref & echo "Pass"

cksrange:
	hex2bin -s 0000 -k 0 -r 01C0 01C8 -f 01C9 00 -c example.hex
	@cmp example.bin ref/cksrange.ref & echo "Pass"

force:
	hex2bin -s 0000 -k 0 -r 01C0 01C8 -F 01C9 00 -c example.hex
	@cmp example.bin ref/force.ref & echo "Pass"

start:
	hex2bin -c -s 0000 example.hex
	@cmp example.bin ref/start.ref & echo "Pass"
	hex2bin -c -s 0000 test-offset-seg.hex
	@cmp test-offset-seg.bin ref/offset-seg.ref & echo "Pass"

maxlength:
	hex2bin -p 3A -l 800000 example.hex
	@cmp example.bin ref/maxlength.ref & echo "Pass"

maxlength2:
	hex2bin -p 3A -l 800000 -s 0 example.hex
	@cmp example.bin ref/maxlength2.ref & echo "Pass"

# -C [Poly][Ìnit][RefIn][RefOut][XorOut]
crc: crc8 crc16 crc32
crc8: 	crc-8-atm \
		crc-8-itu \
		crc-8-rohc \
		crc-8-darc \
		crc-8-icode \
		crc-8-j1850 \
		crc-8-maxim \
		crc-8-wcdma \
		crc-8-ccitt \
		crc-8

crc-8-atm:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 07  0 f f 0 testcrc.hex
	@echo "CRC-8/ATM: expected F4"
	@cmp testcrc.bin ref/testcrc-8-atm.ref & echo "Pass"

crc-8-itu:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 07  0 f f 55 testcrc.hex
	@echo "CRC-8/ITU: expected A1"
	@cmp testcrc.bin ref/testcrc-8-itu.ref & echo "Pass"

crc-8-rohc:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 07 FF t t 0 testcrc.hex
	@echo "CRC-8/ROHC: expected D0"
	@cmp testcrc.bin ref/testcrc-8-rohc.ref & echo "Pass"

crc-8-darc:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 39  0 t t 0 testcrc.hex
	@echo "CRC-8/DARC: expected 15"
	@cmp testcrc.bin ref/testcrc-8-darc.ref & echo "Pass"

crc-8-icode:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 1D FD f f 0 testcrc.hex
	@echo "CRC-8/ICODE: expected 7E"
	@cmp testcrc.bin ref/testcrc-8-icode.ref & echo "Pass"

crc-8-j1850:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 1D FF f f FF testcrc.hex
	@echo "CRC-8/J1850: expected 4B"
	@cmp testcrc.bin ref/testcrc-8-j1850.ref & echo "Pass"

crc-8-maxim:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 31  0 t t 0 testcrc.hex
	@echo "CRC-8/MAXIM: expected A1"
	@cmp testcrc.bin ref/testcrc-8-maxim.ref & echo "Pass"

crc-8-wcdma:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 9B  0 t t 0 testcrc.hex
	@echo "CRC-8/WCDMA: expected 25"
	@cmp testcrc.bin ref/testcrc-8-wcdma.ref & echo "Pass"

crc-8-ccitt:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C 8D  0 f f 0 testcrc.hex
	@echo "CRC-8/CCITT: expected D2"
	@cmp testcrc.bin ref/testcrc-8-ccitt.ref & echo "Pass"

crc-8:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 2 -C D5  0 f f 0 testcrc.hex
	@echo "CRC-8: expected BC"
	@cmp testcrc.bin ref/testcrc-8.ref & echo "Pass"

crc16:	crc-16 \
		crc-16-buypass \
		crc-dds-110 \
		crc-16-maxim \
		crc-usb \
		crc-modbus \
		crc-ccitt-1d0f \
		crc-ccitt-ffff \
		crc-genibus \
		crc-ccitt-xmodem \
		crc-mcrf4xx \
		crc-riello \
		crc-ccitt-kermit \
		crc-x25 \
		crc-dect-r \
		crc-dect-x \
		crc-dnp \
		crc-en-13757 \
		crc-t10-dif \
		crc-teledisk

crc-16:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 0 t t 0 testcrc.hex
	@echo "CRC-16: expected BB3D"
	@cmp testcrc.bin ref/testcrc-16.ref & echo "Pass"

crc-16-buypass:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 0 f f 0 testcrc.hex
	@echo "CRC-16/BUYPASS: expected FEE8"
	@cmp testcrc.bin ref/testcrc-16-buypass.ref & echo "Pass"

crc-dds-110:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 800D f f 0 testcrc.hex
	@echo "CRC-16/DDS-110: expected 9ECF"
	@cmp testcrc.bin ref/testcrc-16-dds-110.ref & echo "Pass"

crc-16-maxim:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 0 t t FFFF testcrc.hex
	@echo "CRC-16/MAXIM: expected 44C2"
	@cmp testcrc.bin ref/testcrc-16-maxim.ref & echo "Pass"

crc-usb:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 FFFF t t FFFF testcrc.hex
	@echo "CRC-16/USB: expected B4C8"
	@cmp testcrc.bin ref/testcrc-16-usb.ref & echo "Pass"

crc-modbus:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8005 FFFF t t 0 testcrc.hex
	@echo "CRC-16/MODBUS: expected 4B37"
	@cmp testcrc.bin ref/testcrc-16-modbus.ref & echo "Pass"

crc-ccitt-1d0f:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 1D0F f f 0 testcrc.hex
	@echo "CRC-16/: expected E5CC"
	@cmp testcrc.bin ref/testcrc-16-ccitt-1d0f.ref & echo "Pass"

crc-ccitt-ffff:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 FFFF f f 0 testcrc.hex
	@echo "CRC-16/CCITT-FFFF: expected 29B1"
	@cmp testcrc.bin ref/testcrc-16-ccitt-ffff.ref & echo "Pass"

crc-genibus:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 FFFF f f FFFF testcrc.hex
	@echo "CRC-16/GENIBUS: expected D64E"
	@cmp testcrc.bin ref/testcrc-16-genibus.ref & echo "Pass"

crc-ccitt-xmodem:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 0 f f 0 testcrc.hex
	@echo "CRC-16/XMODEM: expected 31C3"
	@cmp testcrc.bin ref/testcrc-16-ccitt-xmodem.ref & echo "Pass"

crc-mcrf4xx:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 FFFF t t 0 testcrc.hex
	@echo "CRC-16/MCRF4XX: expected 6F91"
	@cmp testcrc.bin ref/testcrc-16-mcrf4xx.ref & echo "Pass"

crc-riello:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 B2AA t t 0 testcrc.hex
	@echo "CRC-16/RIELLO: expected 63D0"
	@cmp testcrc.bin ref/testcrc-16-riello.ref & echo "Pass"

crc-ccitt-kermit:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 0 t t 0 testcrc.hex
	@echo "CRC-16/CCITT-KERMIT: expected 2189"
	@cmp testcrc.bin ref/testcrc-16-ccitt-kermit.ref & echo "Pass"

crc-x25:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 1021 FFFF t t FFFF testcrc.hex
	@echo "CRC-16/X25: expected 906E"
	@cmp testcrc.bin ref/testcrc-16-x25.ref & echo "Pass"

crc-dect-r:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 0589 0 f f 1 testcrc.hex
	@echo "CRC-16/DECT-R: expected 007E"
	@cmp testcrc.bin ref/testcrc-16-dect-r.ref & echo "Pass"

crc-dect-x:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 0589 0 f f 0 testcrc.hex
	@echo "CRC-16/DECT-X: expected 007F"
	@cmp testcrc.bin ref/testcrc-16-dect-x.ref & echo "Pass"

crc-dnp:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 3D65 0 t t FFFF testcrc.hex
	@echo "CRC-16/DNP: expected EA82"
	@cmp testcrc.bin ref/testcrc-16-dnp.ref & echo "Pass"

crc-en-13757:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 3D65 0 f f FFFF testcrc.hex
	@echo "CRC-16/EN-13757: expected C2B7"
	@cmp testcrc.bin ref/testcrc-16-en-13757.ref & echo "Pass"

crc-t10-dif:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C 8BB7 0 f f 0 testcrc.hex
	@echo "CRC-16/T10-DIF: expected D0DB"
	@cmp testcrc.bin ref/testcrc-16-t10-dif.ref & echo "Pass"

crc-teledisk:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 3 -C A097 0 f f 0 testcrc.hex
	@echo "CRC-16/TELEDISK: expected 0FB3"
	@cmp testcrc.bin ref/testcrc-16-teledisk.ref & echo "Pass"

crc32:	crc-32 crc-32-bzip2 crc-32-mpeg-2 crc-32-posix crc-32-jamcrc \
		crc-32-C crc-32-D crc-32-K crc-32-Q crc-32-xfer

crc-32:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 04C11DB7 FFFFFFFF t t FFFFFFFF testcrc.hex
	@echo "CRC-32: expected CBF43926"
	@cmp testcrc.bin ref/testcrc-32.ref & echo "Pass"

crc-32-bzip2:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 04C11DB7 FFFFFFFF f f FFFFFFFF testcrc.hex
	@echo "CRC-32/BZIP2: expected FC891918"
	@cmp testcrc.bin ref/testcrc-32-bzip2.ref & echo "Pass"

crc-32-mpeg-2:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 04C11DB7 FFFFFFFF f f 0 testcrc.hex
	@echo "CRC-32/MPEG2: expected 0376E6E7"
	@cmp testcrc.bin ref/testcrc-32-mpeg-2.ref & echo "Pass"

crc-32-posix:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 04C11DB7 00000000 f f FFFFFFFF testcrc.hex
	@echo "CRC-32/POSIX: expected 765E7680"
	@cmp testcrc.bin ref/testcrc-32-posix.ref & echo "Pass"

crc-32-jamcrc:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 04C11DB7 FFFFFFFF t t 0 testcrc.hex
	@echo "CRC-32/JAMCRC: expected 340BC6D9"
	@cmp testcrc.bin ref/testcrc-32-jamcrc.ref & echo "Pass"

crc-32-C:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 1EDC6F41 FFFFFFFF t t FFFFFFFF testcrc.hex
	@echo "CRC-32/C: expected E3069283"
	@cmp testcrc.bin ref/testcrc-32-C.ref & echo "Pass"

crc-32-D:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C A833982B FFFFFFFF t t FFFFFFFF testcrc.hex
	@echo "CRC-32/D: expected 87315576"
	@cmp testcrc.bin ref/testcrc-32-D.ref & echo "Pass"

crc-32-K:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 741B8CD7 0 f f 0 testcrc.hex
	@echo "CRC-32/K: expected 085A3197"
	@cmp testcrc.bin ref/testcrc-32-K.ref & echo "Pass"

crc-32-Q:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 814141AB 0 f f 0 testcrc.hex
	@echo "CRC-32/Q: expected 3010BF7F"
	@cmp testcrc.bin ref/testcrc-32-Q.ref & echo "Pass"

crc-32-xfer:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 0 -k 4 -C 000000AF 0 f f 0 testcrc.hex
	@echo "CRC-32/XFER: expected BD0BE338"
	@cmp testcrc.bin ref/testcrc-32-xfer.ref & echo "Pass"

crc-32-xfer-BE:
	hex2bin -c -f 10A -r 100 108 -l 20 -E 1 -k 4 -C 000000AF 0 f f 0 testcrc.hex
	@echo "CRC-32/XFER: expected BD0BE338"
	@cmp testcrc.bin ref/testcrc-32-xfer-BE.ref & echo "Pass"

list_methods:
	hex2bin -d

clean:
	rm *.bin* *.cmd *..cmd
