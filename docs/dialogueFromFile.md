# The dialogueFromFile function

The path should be relative from the directory where your Makefile is.

## Dialogue file structure
Dialogue file stores the informations about nodes, links between them and terminal choices. The file is split into 3 sections representing those informations respectively. Sections should be separated by single empty line. Trailing lines at the end of the file do not cause an exception.  
  
Nodes section stores informations about the nodes. Every node is stored in four lines. Nodes are not separated by empty lines. An example Nodes section looks like this:   
`Welcome to my humble shop, traveller!`  
`Merchant`  
`0`  
`0`  
`So, how can I help you today?`  
`Merchant`  
`0`  
`0`  
`What's the closest city?`  
`You`  
`0`  
`0`  
`Show me your wares.`  
`You`  
`0`  
`0`  
  
Links section stores informations about links between the nodes. Every link is stored in one line, as two integers separated by a single space. Those integers are the indexes used in Dialogue::linkNodes function. An example Links section looks like this:  
`0 1`  
`1 2`  
`2 7`  
`7 1`  
`1 3`  
`3 9`  
`9 1`  
`1 4`  
`4 8`  
`8 1`  
`1 5`  
`5 6`  
  
Terminal choices section stores information about terminal choices. Every terminal choice is stored in one line as an integer. This integer is the index used in Dialogue::addTerminalChoice. An example Terminal choices section looks like this:  
`0`  
`3`  
`6`  
`7`  
  
