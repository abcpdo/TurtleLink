
(cl:in-package :asdf)

(defsystem "rsp_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Move" :depends-on ("_package_Move"))
    (:file "_package_Move" :depends-on ("_package"))
    (:file "Reconfig" :depends-on ("_package_Reconfig"))
    (:file "_package_Reconfig" :depends-on ("_package"))
  ))