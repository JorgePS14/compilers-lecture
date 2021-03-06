# Design of Compilers Final Project

## Design a compiler with a CFG autogenerated by netural network

### Goal

Compiler is a software which converts a program written in high level language
(Source Language) to low level language (Object/Target/Machine Language). The
goal of this project is to generate a compiler usinghelper tools such as YAAC
and LEX but with the difference that the CFG used in the syntax analyser will
not be 100% acurate. An AI system will be the one in charge of generate the CFG
based on validated inputs.

### Design

This is the design of a regular compiler:

```

                                                                  source
                                                                     +
              +-----------+                                          |
bas.y +-----> |           | +---->  y.tab.c +                        |
              |   yaac    |                 |                        v
              |           |                 |
              +-----------+                 +---> +---------+     +--------+
                                                  |   gcc   | +-->+compiler|
                                           +----> +---------+     +--+-----+
                                           |                         |
              +-----------+                |                         |
bas.l +-----> |           | +----> lex.yy.c+                         v
              |  lex      |                                        compiled
              |           |                                        output
              +-----------+

```
The change we are going to do is:
```

                                                  examples of
                                                  valid/invalid
                                                  source code
                                                       +
                                                       |
                                                       |
                                                       v
+------+        +-------+      +--------+        +-----+---+
| CFG  | +----->+ bas.y +----->+ yaac   | +----->+compiler |
+--+---+        +-------+      +--------+        +--+------+
   ^                                                |
   |                                                |
   |                                                v
   |                                       +--------+-----------+
   |                                       |     Artificial     |
   |                                       |     intelligence   |
   +---------------------------------------+     system         |
                                           +--------------------+
```

## Report and presentation

Presentation should be done in front of the team with a writen report made in
latex. The template for it is in this
[link](https://github.com/VictorRodriguez/operating-systems-lecture/blob/master/projects/report.tex)

Teams have to deliver:

	* Printed report
	* Printed LateX code
	* Send presentation to profesor

Resources:
	* https://www.epaperpress.com/lexandyacc/intro.html

