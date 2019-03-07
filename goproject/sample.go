package main

import "fmt"

func main(){
	for i := 1; i<=10; i++{
		if i % 2 == 0{
			fmt.Println(i,"홀수")
		} else {
			fmt.Println(i,"짝수")
		}
	}
}