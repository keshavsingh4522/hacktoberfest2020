package main

import (
  "strings"
  "bufio"
  "fmt"
  "os"
)

func mapper(letter string) int{
  if strings.TrimRight(letter, "\n") == "a" { return 0 }
  if strings.TrimRight(letter, "\n") == "b" { return 1 }
  if strings.TrimRight(letter, "\n") == "c" { return 2 }
  if strings.TrimRight(letter, "\n") == "d" { return 3 }
  if strings.TrimRight(letter, "\n") == "e" { return 4 }
  if strings.TrimRight(letter, "\n") == "f" { return 5 }
  if strings.TrimRight(letter, "\n") == "g" { return 6 }
  if strings.TrimRight(letter, "\n") == "h" { return 7 }
  if strings.TrimRight(letter, "\n") == "i" { return 8 }
  return 99
}

func bprinter (board [9]string) {
  fmt.Println("The board now looks like this:")
  fmt.Println("-------")
  fmt.Println("|" + board[0] + "|" + board[1] + "|" + board[2] + "|")
  fmt.Println("|" + board[3] + "|" + board[4] + "|" + board[5] + "|")
  fmt.Println("|" + board[6] + "|" + board[7] + "|" + board[8] + "|")
  fmt.Println("-------")
  fmt.Println("")
 }

func legendprinter () {
  fmt.Println("Here is the legend for you to make a mark:")
  fmt.Println("_______")
  fmt.Println("|a|b|c|")
  fmt.Println("|d|e|f|")
  fmt.Println("|g|h|i|")
  fmt.Println("-------")
}


func step1(board [9]string, player string) [9]string {
  boardpos := requestor(player)
  newboard := marker(board, player, boardpos)
  tflag := islistsame(board, newboard)
  if (tflag) {
     fmt.Println("No change was made. The same player must make a valid selection. Player " + player + " please try again.")
     newboard = step1(board, player)
  }
  return newboard
}


func boardwinchecker(board [9]string) string {
  lastmessage := "nowinner"
  if board[0] == board[4] { // check the diagonal from left top to right bottom corner
    if board[4] == board[8] {
      if board[4] != " " {
        lastmessage = "Player " + board[0] + " wins!"
        }
    }
  }
  if board[2] == board[4] { // check the diagonal from right top to left bottom corner
    if board[4] == board[6] {
      if board[6] != " " {
        lastmessage = "Player " + board[2] + " wins!"
      }
    }
  }
  if board[0] == board[3] { // check the left column
    if board[3] == board[6] {
      if board[6] != " " {
        lastmessage = "Player " + board[0] + " wins!"
      }
    }
  }
  if board[0] == board[1] { // check the top row
    if board[1] == board[2] {
      if board[0] != " " {
        lastmessage = "Player " + board[0] + " wins!"
      }
    }
  }
  if board[2] == board[5] { // check right column
    if board[5] == board[8] {
      if board[2] != " " {
        lastmessage = "Player " + board[2] + " wins!"
      }
    }
  }
  if board[6] == board[7] { // check bottom row
    if board[7] == board[8] {
      if board[8] != " " {
        lastmessage = "Player " + board[6] + " wins!"
      }
    }
  }
  if board[1] == board[4] { // check middle column
    if board[4] == board[7] {
      if board[1] != " " {
        lastmessage = "Player " + board[1] + " wins!"
      }
    }
  }
  if board[3] == board[4] { // check middle row
    if board[4] == board[5] {
      if board[3] != " " {
        lastmessage = "Player " + board[3] + " wins!"
      }
    }
  }
return lastmessage
}

func marker(board [9]string, player string, position string) [9]string {
  x := mapper(position)
  if (board[x] != " ") {
    fmt.Println("That square has already been marked.  Please try again.")
  } else {
    board[x] = player
  }
  return board
 }

func requestor(player string) string {

fmt.Println("Player", player, "it is your turn.")
fmt.Println("Please enter a letter for the square you want to mark (a through i):")
reader := bufio.NewReader(os.Stdin)
text, _ := reader.ReadString('\n')
if strings.TrimRight(text, "\n") != "a" {
  if strings.TrimRight(text, "\n") != "b" {
    if strings.TrimRight(text, "\n") != "c" {
      if strings.TrimRight(text, "\n") != "d" {
        if strings.TrimRight(text, "\n") != "e" {
          if strings.TrimRight(text, "\n") != "f" {
            if strings.TrimRight(text, "\n") != "g" {
              if strings.TrimRight(text, "\n") != "h" {
                if strings.TrimRight(text, "\n") != "i" {
                  fmt.Println("*** WARNING ***")
                  fmt.Println("That was an invalid entry. Please try again player " + player)
                  fmt.Println(" ")
                  text = requestor(player)
                  }
                }
              }
            }
          }
        }
      }
    }
  }
return text
}

func islistsame(board1 [9]string, board2 [9]string) bool {
  var j = true
  for i := 0; i < 9; i++ {
    if board1[i] == board2[i] {
    } else {
      j = false
    }
 }
  return j
}

func main() {

  var tttb [9]string
  tttb[0] = " "
  tttb[1] = " "
  tttb[2] = " "
  tttb[3] = " "
  tttb[4] = " "
  tttb[5] = " "
  tttb[6] = " "
  tttb[7] = " "
  tttb[8] = " "

legendprinter()

a := step1(tttb, "X")
bprinter(a)
b := step1(a, "O")
bprinter(b)
c := step1(b, "X")
bprinter(c)
d := step1(c, "O")
bprinter(d)
e := step1(d, "X")
bprinter(e)
legendprinter()
be := boardwinchecker(e)
if be == "nowinner" {
  f := step1(e, "O")
  bprinter(f)
  bf := boardwinchecker(f)
  if bf == "nowinner" {
    bprinter(f)
    g := step1(f, "X")
    bg := boardwinchecker(g)
    if bg == "nowinner" {
      bprinter(g)
      h := step1(g, "O")
      bh := boardwinchecker(h)
      if bh == "nowinner" {
        bprinter(h)
        i := step1(h, "X")
        bi := boardwinchecker(i)
        if bi == "nowinner" {
            legendprinter()
            lastmessage := "CAT's GAME. (It was a draw aka a tie game.)"
            bprinter(i)
            fmt.Println(lastmessage)
        } else {
            bprinter(i)
            fmt.Println(bi) }
      } else {
           bprinter(h)
           fmt.Println(bh) }
     } else {
          bprinter(g)
          fmt.Println(bg) }
   }  else {
          bprinter(f)
          fmt.Println(bf) }
  } else {
       bprinter(e)
       fmt.Println(be) }
 }
