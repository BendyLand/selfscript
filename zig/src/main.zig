const std = @import("std");
const tokens = @import("tokens.zig");
const utils = @import("utils.zig");
const Token = tokens.Token;
const print = std.debug.print;

pub fn main() !void {
    var allocator = std.heap.page_allocator;
    const args = utils.split("<cond1> <cond2> <cond3>", ' ', &allocator);
    defer allocator.free(args);
    const token = Token.init("if", args);
    print("Name: {s}\n", .{token.getNameStr()});
    print("Args: {s}\n", .{token.getArgs()});
}
