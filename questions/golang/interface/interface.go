package main

import "fmt"

type People interface {
	Speak(string) string
}

type Student struct {
}

func (stu *Student) Speak(think string) (talk string) {
	if think == "good" {
		talk = "You are a good boy"
	} else {
		talk = "hi"
	}
	return
}

func main() {
	var peo People = new(Student)
	fmt.Println(peo.Speak("good"))
}
