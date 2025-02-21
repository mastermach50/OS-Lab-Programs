use std::{
    io::{prelude::*, BufReader},
    net::{TcpListener, TcpStream},
};
use std::{thread, time::Duration};

fn main() {
    let listener = TcpListener::bind("127.0.0.1:7878").unwrap();

    for stream in listener.incoming() {
        let stream = stream.unwrap();

        handle_connection(stream);
    }
}

fn handle_connection(mut stream: TcpStream) {
    let buf_reader = BufReader::new(&stream);
    let http_request: Vec<_> = buf_reader
        .lines()
        .map(|result| result.unwrap())
        .take_while(|line| !line.is_empty())
        .collect();

    println!("Request: {http_request:#?}");

    let response = "\
HTTP/1.1 200 OK
Content-Length: 14

Hello";
    stream.write(response.as_bytes()).unwrap();
    thread::sleep(Duration::from_millis(4000));
    stream.write("Then this".as_bytes()).unwrap();
}