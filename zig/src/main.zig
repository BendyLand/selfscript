const std = @import("std");
const tokens = @import("tokens.zig");
const Token = tokens.Token;

pub fn main() void {
    const token = Token.init("if", "<condition>");
    
    std.debug.print("Name: {s}\n", .{Token.nameToStr(token.getName())});
    std.debug.print("Args: {s}\n", .{token.getArgs()});
}
