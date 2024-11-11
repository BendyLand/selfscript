const std = @import("std");
const bufPrint = std.fmt.bufPrint();
pub const String = []const u8;
pub const StringArray = []const []const u8;

pub fn split(input: String, delimiter: u8, allocator: *std.mem.Allocator) StringArray {
    var parts = std.ArrayList([]const u8).init(allocator.*);
    defer parts.deinit();
    var start: usize = 0;
    var i: usize = 0;
    while (i < input.len) : (i += 1) {
        if (input[i] == delimiter) {
            // Attempt to append the slice; if it fails, handle the error without propagating it
            parts.append(input[start..i]) catch |err| {
                std.debug.print("Error appending part: {any}\n", .{err});
                return &[_][]const u8{};
            };
            start = i + 1;
        }
    }
    // Append the final segment after the last delimiter
    if (start < input.len) {
        parts.append(input[start..]) catch |err| {
            std.debug.print("Error appending final part: {any}\n", .{err});
            return &[_][]const u8{};
        };
    }
    // Convert to owned slice, handle any allocation error, and return a non-error-union type
    return parts.toOwnedSlice() catch |err| {
        std.debug.print("Error converting to owned slice: {any}\n", .{err});
        return &[_][]const u8{};
    };
}

pub fn readFileToString(filename: []const u8, allocator: *std.mem.Allocator) ![]const u8 {
    const file = try std.fs.cwd().openFile(filename, .{.mode = .read_only});
    defer file.close();
    const file_size = try file.getEndPos();
    const buffer = try allocator.alloc(u8, file_size);
    const bytes_read = try file.readAll(buffer);
    if (bytes_read != file_size) {
        return error.UnexpectedEOF;
    }
    return buffer;
}