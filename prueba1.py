import sys

def wc(argv):
    argc = len(argv)
    tlinect = 1
    twordct = 1
    tcharct = 1

    for i in range (0,argc):
        try:
            charct = 0
            wordct = 0
            linect = 0

            with open(argv[i],'r',encoding = 'utf-8') as fp:
                for line in fp:
                    linect += 1
                    wordct += len(line.split())
                    charct += len(line)

            print("resultados lineas: ", linect," palabras: ", wordct," caracteres: ", charct)
            if argc > 1:
                print("  ", *argv)
            else:
                print("\n")
            
            tlinect += linect
            twordct += wordct
            tcharct += charct
        except Exception as err:
            print("can't open"+argv[i], err)
        
        if argc > 1:
            print(" Total:\n lineas: ", linect," palabras: ", twordct," caracteres: ", tcharct)

wc(sys.argv)