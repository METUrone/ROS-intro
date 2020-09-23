
(cl:in-package :asdf)

(defsystem "meturone_egitim-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Dummy" :depends-on ("_package_Dummy"))
    (:file "_package_Dummy" :depends-on ("_package"))
    (:file "answer" :depends-on ("_package_answer"))
    (:file "_package_answer" :depends-on ("_package"))
  ))