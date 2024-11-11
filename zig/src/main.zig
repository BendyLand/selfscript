const std = @import("std");
const tokens = @import("tokens.zig");
const utils = @import("utils.zig");
const Lexer = @import("lexer.zig").Lexer;
const Token = tokens.Token;
const print = std.debug.print;

pub fn main() !void {
    var allocator = std.heap.page_allocator;
    var token = try Token.init("if", "<cond1> <cond2>", &allocator);
    defer token.deinit(&allocator);
    // print("Name: {s}\n", .{token.getNameStr()});
    // print("Args: {s}\n", .{token.getArgs()});
    const file = try utils.readFileToString("../../test.ss", &allocator);
    defer allocator.free(file);
    var lexer = try Lexer.init(file, allocator);
    // print("{s}\n", .{lexer.file});
    // print("{any}\n", .{lexer.tokens.items});
    try lexer.tokenize(&allocator);
}
