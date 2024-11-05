import std/[strutils, options]

type
  Name* = enum
    CP, MV, RM, MKDIR, CHECK_ENV, SET_ENV, UNSET_ENV, EXEC, PUTS, PROMPT,
    CONFIRM, IF, THEN, ELSE, END, COND, FOR, DO, LABEL, GOTO, DOWNLOAD, UPLOAD,
    UNKNOWN

  Token* = object
    name: Name
    args: Option[seq[string]]

proc strToName*(name: string): Name =
  case name
  of "cp": return Name.CP
  of "mv": return Name.MV
  of "rm": return Name.RM
  of "mkdir": return Name.MKDIR
  of "check_env": return Name.CHECK_ENV
  of "set_env": return Name.SET_ENV
  of "unset_env": return Name.UNSET_ENV
  of "exec": return Name.EXEC
  of "puts": return Name.PUTS
  of "prompt": return Name.PROMPT
  of "confirm": return Name.CONFIRM
  of "if_": return Name.IF
  of "then": return Name.THEN
  of "else_": return Name.ELSE
  of "end": return Name.END
  of "cond": return Name.COND
  of "for_": return Name.FOR
  of "do": return Name.DO
  of "label": return Name.LABEL
  of "goto": return Name.GOTO
  of "download": return Name.DOWNLOAD
  of "upload": return Name.UPLOAD
  else: return Name.UNKNOWN

proc nameToStr*(name: Name): string =
  case name
  of Name.CP: "cp"
  of Name.MV: "mv"
  of Name.RM: "rm"
  of Name.MKDIR: "mkdir"
  of Name.CHECK_ENV: "check_env"
  of Name.SET_ENV: "set_env"
  of Name.UNSET_ENV: "unset_env"
  of Name.EXEC: "exec"
  of Name.PUTS: "puts"
  of Name.PROMPT: "prompt"
  of Name.CONFIRM: "confirm"
  of Name.IF: "if"
  of Name.THEN: "then"
  of Name.ELSE: "else"
  of Name.END: "end"
  of Name.COND: "cond"
  of Name.FOR: "for"
  of Name.DO: "do"
  of Name.LABEL: "label"
  of Name.GOTO: "goto"
  of Name.DOWNLOAD: "download"
  of Name.UPLOAD: "upload"
  of Name.UNKNOWN: "unknown"

proc getName*(token: Token): Name =
  token.name

proc getNameStr*(token: Token): string =
  nameToStr(token.name)

proc getArgs*(token: Token): seq[string] =
  if token.args.isSome:
    token.args.get()
  else:
    @[] 

proc initToken*(name: string, line: string): Token =
  let splitArgs = line.split(' ')
  result = Token(name: strToName(name), args: some(splitArgs))

# may not be needed, since no allocation needed.
proc deinitToken*(token: var Token) =
  if token.args.isSome:
    token.args = none(seq[string])
