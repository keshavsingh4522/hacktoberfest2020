def pisah(email):
    try:
        asw = email.split("|")[0]
        q = asw.split("@")
        file = q[1].split(".")[0] + ".txt"
        with open(file, "a") as exc:
            exc.write(asw+"\n")
            exc.close()
    except:
        pass

for i in open(input("List Email : "), "r").read().splitlines():
    pisah(i)
