" Quit when a syntax file was already loaded.
if exists('b:current_syntax') | finish|  endif

syn region particleProperty start='\[' end='\]' contains=particleTypes nextgroup=properties
syn region particleProperty start='(' end=')' contains=particleTypes nextgroup=properties
syn region particleProperty start='{' end='}' contains=particleTypes nextgroup=properties
syn keyword properties Eta m q Pt abs AbsEta alias dR pT PDGID eta Pz E ascend descend 

syn keyword particleTypes Zreco JET ELE MUO LEP TAU PHO JET BJET QGJET NUMET METLV GEN 
syn keyword particleTypes JET_ ELE_ MUO_ LEP_ TAU_ PHO_ JET_ BJET_ QGJET_ NUMET_ METLV_ GEN_ nextgroup=intValue

syn match equators "[>~<=!]" nextgroup=intValue skipwhite
syn match punctuators '[+-\(\)\{\}\]&|_"]'
syn keyword functions def cmd cut command algo algorithm region weight object histo define select save reject Bin Sort sort table take nextgroup=varName skipwhite
syn keyword functions def cmd cut command algo algorithm region weight object histo define select save reject Bin Sort sort table take nextgroup=properties skipwhite

syn match varName "\k\+" nextgroup=simpleAssignment skipwhite
syn match simpleAssignment ":" contained nextgroup=particleTypes
"syn match simpleValue ".*" contained

syn match comment "#" nextgroup=text skipwhite

" String assingment 
syn match text "\k\+" contained nextgroup=text skipwhite
syn match text "[.'\[\],";:{}=()*&^%$#@!<>\?/+-]" contained nextgroup=text skipwhite

" Number Assignment
syn match constValue '\d\+'
syn match constValue '[-+]\d\+'
syn match constValue '[-+]\d\+\.\d*'

hi def link functions Type 
hi def link varName Identifier
hi def link text Comment
hi def link simpleAssignment Statement
hi def link equators Operator
hi def link constValue Constant
hi def link punctuators Operator
hi def link properties NonText
"hi def link simpleValue String

let b:current_syntax = 'cutlang'
