package main

import "fmt"

func main(){
	x := make(map[string]string)
	x["H"] = "Hydrogen"
	x["He"] = "Helium"
	x["Li"] = "Lithium"
	x["Be"] = "Beryllium"
	x["B"] = "Boron"
	x["C"] = "Carbon"
	x["N"] = "Nitrogen"
	x["O"] = "Oxygen"
	x["F"] = "Fluorine"
	x["Ne"] = "Neon"
	name, ok := x["Un"]
	fmt.Println("name, ok")
}