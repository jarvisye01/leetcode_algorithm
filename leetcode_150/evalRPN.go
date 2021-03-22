package main

import (
    "fmt"
    "reflect"
    "strconv"
)

type Stack interface {
    Size() int
    Empty() bool
    Pop() interface{}
    Push(e interface{})
    ElemType() reflect.Kind
}

type stack struct {
    arr []interface{}
    sz  int
    kind reflect.Kind
}

func (s *stack) resize(cap int) {
    copy := make([]interface{}, cap)
    for i := 0; i < s.Size(); i++ {
        copy[i] = s.arr[i]
    }
    s.arr = copy
}

func (s *stack) Size() int {
    return s.sz
}

func (s *stack) Empty() bool {
    return s.sz == 0
}

func (s *stack) ElemType() reflect.Kind {
    return s.kind
}

func (s *stack) Push(e interface{}) {
    if s.sz == len(s.arr) {
        s.resize(len(s.arr) * 2)
    }
    s.arr[s.sz] = e
    s.sz++
}

func (s *stack) Pop() interface{} {
    if s.sz == len(s.arr) / 4 {
        s.resize(len(s.arr) / 4)
    }
    x := s.arr[s.sz - 1]
    s.arr[s.sz - 1] = nil
    s.sz--
    return x
}

func GetStack(k reflect.Kind) Stack {
    return &stack{
        sz: 0,
        arr: make([]interface{}, 8),
        kind: k,
    }
}

func isOperator(op string) bool {
    return op == "+" || op == "-" || op == "*" || op == "/"
}

func Compute(x, y int, op string) int {
    switch op {
    case "+":
        return x + y
    case "-":
        return x - y
    case "*":
        return x * y
    case "/":
        return x / y
    }
    return 0
}

func evalRPN(tokens []string) int {
    s := GetStack(reflect.String)
    for i := 0; i < len(tokens); i++ {
        if isOperator(tokens[i]) {
            e1 := s.Pop().(string)
            e2 := s.Pop().(string)
            x, _ := strconv.Atoi(e2)
            y, _ := strconv.Atoi(e1)
            s.Push(strconv.Itoa(Compute(x, y, tokens[i])))
            continue
        }
        s.Push(tokens[i])
    }

    for s.Size() > 1 {
        op, _ := s.Pop().(string)
        if !isOperator(op) {
            return -1
        }
        e1, _ := s.Pop().(string)
        e2, _ := s.Pop().(string)
        x, _ := strconv.Atoi(e2)
        y, _ := strconv.Atoi(e1)
        s.Push(Compute(x, y, op))
    }

    e, _ := s.Pop().(string)
    res, _ := strconv.Atoi(e)
    return res
}

func main() {
    tokens := []string{"4","-2","/","2","-3","-","-"}
    res := evalRPN(tokens)
    fmt.Println(res)
}
