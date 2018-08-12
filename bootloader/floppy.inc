oemName                  DB "ZIGGURAT"
bpbBytesPerSector        DW 512
bpbSectorsPerCluster     DB 1
bpbReservedSectors       DW 1 
bpbNumberOfFATs          DB 2
bpbRootEntries           DW 224
bpbTotalSectors          DW 2880
bpbMedia                 DB 0f0h 
bpbSectorsPerFAT         DW 9
bpbSectorsPerTrack       DW 18 
bpbHeadsPerCylinder      DW 2 
bpbHiddenSectors         DD 0
bpbTotalSectorsBig       DD 0
bsDriveNumber            DB 0
bsUnused                 DB 0
bsExtBootSignature       DB 29
bsSerialNumber           DD 0 
bsVolumeLabel            DB "Ziggurat OS"
bsFileSystem             DB "FAT12   "

