# scrollslasher
Converts a textfile containing ASCII scrolltext to Amiga-assembly-friendly data. It accidentally also solves arguments between Slash and Origo on how to write scrolltexts for Amiga demos.

##Example usage
`scrollslasher.exe <file> <page width> <page height>`

##Example output
~~~~
  dc.b 'THIS IS A STANDARD SC'
  dc.b 'ROLLTEXT THAT IS GOIN'
  dc.b 'G TO BE CONVERTED INT'
  dc.b 'O AMIGA-ASSEMBLY-FRIE'
  dc.b 'NDLY FORMAT BY SCROLL'
  dc.b 'SLASHER              '
  
  dc.b -1
~~~~
