package main

import (
	"strings"
	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	words := strings.Fields(s)
	ans := make(map[string]int)
	for _, data := range words{
		_, val := ans[data]
		if val{
			ans[data] += 1
		}else{
			ans[data] = 1
		}
	}
	return ans
}

func main() {
	wc.Test(WordCount)
}