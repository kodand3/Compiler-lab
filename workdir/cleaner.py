with open("mylex.l", "r") as file:
    lines = file.readlines()

# Strip spaces and remove blank lines
cleaned = [line.strip() for line in lines if line.strip()]

with open("final.l", "w") as file:
    file.write("\n".join(cleaned))

