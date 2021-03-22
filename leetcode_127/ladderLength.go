package main

import (
    "container/list"
    "fmt"
    "strings"
)

//func compare(s1 string, s2 string) bool {
//    if len(s1) != len(s2) {
//        return false
//    }
//    t := 0
//    for i := 0; i < len(s1); i++ {
//        if s1[i] != s2[i] {
//            t++
//            if t > 1 {
//                return false
//            }
//        }
//    }
//    return t == 1
//}
//
//var info = map[string]int{}
//const MAX = 1 << 30
//
//func DFS(b string, s string, words []string, path map[string]int, minPath *int) {
//   if strings.Compare(b, s) == 0 {
//       N := len(path)
//       if N < *minPath {
//           *minPath = N
//       }
//       for k, v := range path {
//           if N - v < info[k] {
//               info[k] = N - v + 1
//           }
//       }
//       return
//   }
//
//   for i := 0; i < len(words); i++ {
//       _, ok := path[words[i]]
//       if compare(b, words[i]) && !ok {
//           if info[words[i]] == -1 {
//               continue
//           }
//           if info[words[i]] != MAX {
//               if len(path) + info[words[i]] < *minPath {
//                   fmt.Println(info)
//                   *minPath = len(path) + info[words[i]]
//               }
//               continue
//           } else {
//               path[words[i]] = len(path) + 1
//               DFS(words[i], s, words, path, minPath)
//               delete(path, words[i])
//           }
//       }
//   }
//   for _, w := range words {
//       _, ok := path[w]
//       if compare(b, w) && !ok {
//           if info[w] + 1 < info[b] {
//               info[b] = info[w] + 1
//           }
//       }
//   }
//}
//
//func ladderLength(beginWord string, endWord string, wordList []string) int {
//    isThere := false
//    for i := 0; i < len(wordList); i++ {
//        info[wordList[i]] = MAX
//        if wordList[i] == endWord {
//            isThere = true
//        }
//    }
//    if !isThere {
//        return 0
//    }
//    info[endWord] = 1
//    res := MAX
//    DFS(beginWord, endWord, wordList, map[string]int{}, &res)
//    if res == MAX {
//        return 0
//    }
//    return res + 1
//}


func compare(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }
    t := 0
    for i := 0; i < len(s1); i++ {
        if s1[i] != s2[i] {
            t++
            if t > 1 {
                return false
            }
        }
    }
    return t == 1
}

var info = map[int]int{}

func DFS(b string, s string, words []string, path map[int]int, minPath *int) {
    if strings.Compare(b, s) == 0 {
        N := len(path)
        if N < *minPath {
            *minPath = N
        }
    }

    for i := 0; i < len(words); i++ {
        _, ok := path[i]
        if compare(b, words[i]) && !ok {
            path[i] = 1
            DFS(words[i], s, words, path, minPath)
            delete(path, i)
        }
    }
}

//func ladderLength(beginWord string, endWord string, wordList []string) int {
//    const m = 1 << 30
//    res := m
//    DFS(beginWord, endWord, wordList, map[int]int{}, &res)
//    if res == m {
//         return 0
//    }
//    return res + 1
//}

func ladderLength(beginWord string, endWord string, wordList []string) int {
    words := map[string]bool{}
    isThere := false
    for i := 0; i < len(wordList); i++ {
        if wordList[i] == endWord {
            isThere = true
        }
        words[wordList[i]] = true
    }
    if  !isThere {
        return 0
    }

    res := 0
    q := list.New()
    q.PushBack(beginWord)
    flag := false
    isVisited := map[string]bool{}
    for q.Len() > 0 {
        t := q.Len()
        res++
        for i := 0; i < t; i++ {
            e := q.Remove(q.Front())
            s := e.(string)
            d := []string{}
            for item, _ := range words {
                if compare(s, item) {
                    if !isVisited[item] {
                        isVisited[item] = true
                        q.PushBack(item)
                    }
                    if item == endWord {
                        flag = true
                    }
                    d = append(d, item)
                }
            }
            for _, s := range d {
                delete(words, s)
            }
        }
        if flag {
            break
        }
    }
    if !flag {
        return 0
    }
    return res + 1
}

func main() {
    ws := []string{"hot", "hog", "tog", "cog"}
    fmt.Println(ladderLength("hit", "cog", ws))
}