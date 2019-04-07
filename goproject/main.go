package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	filename := "users.json"
	b, err:=ioutil.ReadFile(filename)
	if err!= nil{
		contents:="blah blah"
		err := ioutil.WriteFile(filename, []byte(contents), 0644)
		if err!=nil{
			fmt.Println(err)
			os.Exit(1)
		}
		fmt.Println("file created")
		return
	}

	s := string(b)
	fmt.Println(s)
}
 